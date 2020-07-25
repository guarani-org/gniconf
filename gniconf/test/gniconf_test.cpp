#include "gniconf_test.h"

int main(void) {
  imu_config_t imuc;
 // imuc.parse("d:\\temp\\teste.xml");
  imuc.serialize("d:\\temp\\teste.xml");
  return 0;
}