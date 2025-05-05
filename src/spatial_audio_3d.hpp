#ifndef TEGODOT_SPATIAL_AUDIO_PLAYER_3D_HPP
#define TEGODOT_SPATIAL_AUDIO_PLAYER_3D_HPP

#include <godot_cpp/classes/audio_stream_player3d.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

namespace tegodot
{
  class SpatialAudioPlayer3D : public AudioStreamPlayer3D
  {
  GDCLASS(SpatialAudioPlayer3D, AudioStreamPlayer3D)

  protected:
    static void _bind_methods();

  private:
    double max_raycast_distance;

  public:
    void set_max_raycast_distance(const double p_max_distance);
    double get_max_raycast_distance() const;

    SpatialAudioPlayer3D();
    ~SpatialAudioPlayer3D();
  };
}

#endif
