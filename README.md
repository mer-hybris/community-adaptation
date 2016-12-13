community-adaptation
====================

This package is responsible for providing SSU `features.d` repositories, which
will enable proper SSU functionality on community adaptations, setting up paths
to access to Jolla Store (if enabled for your device) and OTA updates.

This package will be available in two flavours: in Mer OBS `nemo:devel:*`
projects -- `devel` flavour, and on `nemo:testing:*` ... you guessed it right :)

`community-adaptation-testing` flavour will disable telnet access to the device.

To embrace these features, a community adaptation should:
* `%define community_adaptation 1` in their `droid-configs` device .spec file
* Add `nemo:devel:hw:common` as additional repository to their OBS
  `nemo:devel:hw:$VENDOR:$DEVICE` repo, and the same for `testing`

