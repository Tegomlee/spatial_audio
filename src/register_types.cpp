#include "register_types.hpp"

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <../godot-cpp/gdextension/gdextension_interface.h>

#include "spatial_audio_3d.hpp"

using namespace godot;

void initialize_tegodot_spatial_audio_module(
    ModuleInitializationLevel p_level) 
{
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  GDREGISTER_RUNTIME_CLASS(tegodot::SpatialAudioPlayer3D);
}

void uninitialize_tegodot_spatial_audio_module(
    ModuleInitializationLevel p_level) 
{
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}

extern "C"
{
  GDExtensionBool GDE_EXPORT tegodot_spatial_audio_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
    const GDExtensionClassLibraryPtr p_library,
    GDExtensionInitialization* r_initialization)
  {
  godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
                                                 r_initialization);

  init_obj.register_initializer(initialize_tegodot_spatial_audio_module);
  init_obj.register_terminator(uninitialize_tegodot_spatial_audio_module);
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
  }
}
