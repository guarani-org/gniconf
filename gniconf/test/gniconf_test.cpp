#include "gniconf_test.h"

int main(void) {
  gniconfig_t cfg;
  cfg.parse("D:\\temp\\gniconf.xml");
  cfg.create("D:\\temp\\gniconf.xml");
  return 0;
}