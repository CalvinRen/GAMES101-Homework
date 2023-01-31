//
// Created by Göksu Güvendiren on 2019-05-14.
//

#include "Scene.hpp"
#include<math.h>

void Scene::buildBVH() {
    printf(" - Generating BVH...\n\n");
    this->bvh = new BVHAccel(objects, 1, BVHAccel::SplitMethod::NAIVE);
}

Intersection Scene::intersect(const Ray &ray) const
{
    return this->bvh->Intersect(ray);
}

void Scene::sampleLight(Intersection &pos, float &pdf) const
{
    float emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
        }
    }
    float p = get_random_float() * emit_area_sum;
    emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
            if (p <= emit_area_sum){
                objects[k]->Sample(pos, pdf);
                break;
            }
        }
    }
}

bool Scene::trace(
        const Ray &ray,
        const std::vector<Object*> &objects,
        float &tNear, uint32_t &index, Object **hitObject)
{
    *hitObject = nullptr;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        float tNearK = kInfinity;
        uint32_t indexK;
        Vector2f uvK;
        if (objects[k]->intersect(ray, tNearK, indexK) && tNearK < tNear) {
            *hitObject = objects[k];
            tNear = tNearK;
            index = indexK;
        }
    }


    return (*hitObject != nullptr);
}

// Implementation of Path Tracing
Vector3f Scene::castRay(const Ray &ray, int depth) const
{
    // TODO Implement Path Tracing Algorithm here

    Intersection inter_p = intersect(ray);
    // if no intersection, return background color
    if (!inter_p.happened) {
        return {0, 0, 0};
    }
    // if intersects with light source, return light color
    if (inter_p.m->hasEmission()) {
        if (depth == 0) return inter_p.m->getEmission();
        else return {0, 0, 0};
    }
    // direct illumination
    Intersection inter_light;
    float pdf_light = 0.0f;
    sampleLight(inter_light, pdf_light);
    // Get x, ws, NN, emit
    Vector3f p = inter_p.coords;
    Vector3f x = inter_light.coords;
    Vector3f ws_dir = (x - p).normalized(); // points to x
    float ws_dis = (x - p).norm();
    Vector3f NN = inter_light.normal.normalized();
    Vector3f N = inter_p.normal.normalized();
    Vector3f emit = inter_light.emit;

    // Shoot a ray from p to x
    Vector3f L_dir = 0.0;
    Ray light_ray(p, ws_dir);
    Intersection inter_p_light = intersect(light_ray);
    if ((inter_p_light.distance - ws_dis) > -0.0001) {
        L_dir = emit * inter_p.m->eval(ray.direction, light_ray.direction, N) * dotProduct(light_ray.direction, N) * dotProduct(-light_ray.direction, NN) / std::pow(ws_dis, 2) / pdf_light;
    }

    // indirect illumination
    // Test Russian Roulette
    if (get_random_float() > RussianRoulette) return L_dir;

    Vector3f L_indir  = 0.0;
    // Test Russian Roulette with probability RussianRoulette
    Vector3f wi_dir = inter_p.m->sample(ray.direction, N).normalized();
    Ray ray_indir(inter_p.coords, wi_dir);

    // if ray r hit a non-emitting object
    Intersection inter_indir = intersect(ray_indir);
    if (inter_indir.happened && !inter_indir.m->hasEmission()) {
        L_indir = castRay(ray_indir, depth + 1) * inter_p.m->eval(ray.direction, ray_indir.direction, N) * dotProduct(ray_indir.direction, N) / inter_p.m->pdf(ray.direction, ray_indir.direction, N) / RussianRoulette;
    }

    return L_dir + L_indir;
}