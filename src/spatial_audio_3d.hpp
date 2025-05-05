#ifndef TEGODOT_SPATIAL_AUDIO_PLAYER_3D_HPP
#define TEGODOT_SPATIAL_AUDIO_PLAYER_3D_HPP

#include <vector>

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
    // Members exposed to Godot

    double max_raycast_distance;
    bool debug_draw_enabled;

    // Truly private members

    static const std::vector<Vector3> _directions;
    static const std::vector<Vector3> generate_directions();

  public:
    void set_max_raycast_distance(const double p_max_distance);
    double get_max_raycast_distance() const;

    void set_debug_draw_enabled(bool p_enabled);
    bool is_debug_draw_enabled() const;

    SpatialAudioPlayer3D();
    ~SpatialAudioPlayer3D();
  };
}

#endif
