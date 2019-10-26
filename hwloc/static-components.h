#include <private/internal-components.h>
#if defined(_MSC_VER) || defined(MINGW_SDK_INIT)
static const struct hwloc_component * hwloc_static_components[] = {
  &hwloc_noos_component,
  &hwloc_xml_component,
  &hwloc_synthetic_component,
  &hwloc_xml_nolibxml_component,
  &hwloc_windows_component,
  &hwloc_x86_component,
  NULL
};
#else
static const struct hwloc_component * hwloc_static_components[] = {
  &hwloc_noos_component,
  &hwloc_xml_component,
  &hwloc_synthetic_component,
  &hwloc_xml_nolibxml_component,
  &hwloc_linux_component,
  &hwloc_x86_component,
  NULL
};
#endif
