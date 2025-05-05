#include "spatial_audio_3d.hpp"

#include <godot_cpp/core/property_info.hpp>

using namespace godot;

namespace tegodot 
{
const std::vector<Vector3> SpatialAudioPlayer3D::_directions =
    SpatialAudioPlayer3D::generate_directions();

void SpatialAudioPlayer3D::_bind_methods() 
{ 
  // Add the max_raycast_distance to Godot
  ClassDB::bind_method(D_METHOD("set_max_raycast_distance", "p_max_distance"),
                       &SpatialAudioPlayer3D::set_max_raycast_distance);
  ClassDB::bind_method(D_METHOD("get_max_raycast_distance"),
                       &SpatialAudioPlayer3D::get_max_raycast_distance);
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_raycast_distance"),
               "set_max_raycast_distance", "get_max_raycast_distance");

  // Add the debug_draw_enabled to  Godot
  ClassDB::bind_method(D_METHOD("set_debug_draw_enable", "p_enabled"),
                       &SpatialAudioPlayer3D::set_debug_draw_enabled);
  ClassDB::bind_method(D_METHOD("is_debug_draw_enabled"),
                       &SpatialAudioPlayer3D::is_debug_draw_enabled);
  ADD_PROPERTY(PropertyInfo(Variant::BOOL, "debug_draw_enabled"),
               "set_max_raycast_distance", "is_debug_draw_enabled");
}

const std::vector<Vector3> SpatialAudioPlayer3D::generate_directions()
{
  std::vector<Vector3> directions;
  
  // 6 axis-aligned directions
  directions.emplace_back(Vector3(1, 0, 0).normalized());
  directions.emplace_back(Vector3(-1, 0, 0).normalized());
  directions.emplace_back(Vector3(0, 1, 0).normalized());
  directions.emplace_back(Vector3(0, -1, 0).normalized());
  directions.emplace_back(Vector3(0, 0, 1).normalized());
  directions.emplace_back(Vector3(0, 0, -1).normalized());

  // Roughly 10° angular spacing → ~412 points on a sphere (assuming ~π steradian per point)
  const size_t num_samples = 400U;
  const float offset = 2.0f / num_samples;
  const float increment = Math_TAU * (3.0f - sqrtf(5.0f)); // golden angle in radians

  for (size_t i = 0U; i < num_samples; ++i)
  {
    float y = ((i * offset) - 1.0f) + (offset / 2.0f);
    float r = sqrtf(1.0f - y * y);
    float phi = i * increment;

    float x = cosf(phi) * r;
    float z = sinf(phi) * r;

    directions.emplace_back(Vector3(x, y, z).normalized());
  }

  return directions;
}

void SpatialAudioPlayer3D::set_max_raycast_distance(
    const double p_max_distance) 
{
  max_raycast_distance = p_max_distance;
}

double SpatialAudioPlayer3D::get_max_raycast_distance() const 
{ 
  return max_raycast_distance; 
}

void SpatialAudioPlayer3D::set_debug_draw_enabled(bool p_enabled)
{
  debug_draw_enabled = p_enabled;
}

bool SpatialAudioPlayer3D::is_debug_draw_enabled() const
{
  return debug_draw_enabled;
}

SpatialAudioPlayer3D::SpatialAudioPlayer3D() 
{ 
  max_raycast_distance = 30.0; 
  debug_draw_enabled = false;
}

SpatialAudioPlayer3D::~SpatialAudioPlayer3D() {}
} // namespace tegodot
