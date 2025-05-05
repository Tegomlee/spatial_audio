#include "spatial_audio_3d.hpp"

#include <godot_cpp/core/property_info.hpp>

using namespace godot;

namespace tegodot 
{
void SpatialAudioPlayer3D::_bind_methods() 
{ 
  ClassDB::bind_method(D_METHOD("set_max_raycast_distance", "p_max_distance"),
                       &SpatialAudioPlayer3D::set_max_raycast_distance);
  ClassDB::bind_method(D_METHOD("get_max_raycast_distance"),
                       &SpatialAudioPlayer3D::get_max_raycast_distance);

  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_raycast_distance"),
               "set_max_raycast_distance", "get_max_raycast_distance");
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

SpatialAudioPlayer3D::SpatialAudioPlayer3D() 
{ max_raycast_distance = 30.0; }

SpatialAudioPlayer3D::~SpatialAudioPlayer3D() {}
}
