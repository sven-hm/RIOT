include ../Makefile.tests_common

# generate random free port
DHCPV6_SERVER_PORT := 61342

RIOTBASE ?= $(CURDIR)/../..

# boards don't support ethos
BOARD_BLACKLIST += mips-malta pic32-wifire pic32-clicker ruuvitag thingy52

USEMODULE += gnrc_dhcpv6_client
USEMODULE += gnrc_ipv6_default
USEMODULE += xtimer
ifneq (,$(filter native,$(BOARD)))
  # Has to be provided here and not in Makefile.dep, so TERMFLAGS are properly
  # configured
  USEMODULE += netdev_default
  IFACE ?= tapbr0
else
  IFACE ?= tap0
  ETHOS_BAUDRATE ?= 115200
  CFLAGS += -DETHOS_BAUDRATE=$(ETHOS_BAUDRATE)
  TERMPROG ?= sudo $(RIOTBASE)/dist/tools/ethos/ethos
  TERMFLAGS ?= $(IFACE) $(PORT) $(ETHOS_BAUDRATE)
  TERMDEPS += ethos
endif
USEMODULE += auto_init_gnrc_netif

USEMODULE += shell_commands

CFLAGS += -DDHCPV6_SERVER_PORT=$(DHCPV6_SERVER_PORT)

TEST_DEPS += dhcpv6_server

# The test requires to be run as root
TEST_ON_CI_BLACKLIST += all

include $(RIOTBASE)/Makefile.include

.PHONY: dhcpv6_server

dhcpv6_server:
	$(CURDIR)/dhcpv6_server.sh $(DHCPV6_SERVER_PORT) $(CURDIR)/kea-dhcp6.conf

ifeq (,$(filter native,$(BOARD)))
.PHONY: ethos

ethos:
	$(Q)env -u CC -u CFLAGS make -C $(RIOTBASE)/dist/tools/ethos
endif
