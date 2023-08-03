## Features

#### Commands
* `copyip`
* `listassets <asset type>`
* `mvm_addnode`
* `mvm_playdolly`
* `mvm_clearnodes`

#### Dvars
* `com_redirect [1/0]`
* `cl_autorecord [1/0]`
* `cl_autorecord_output <template>`
* `r_windowedfullscreen [1/0]`
* `r_world_material <name>`
* `r_world_techtype <index>`
* `r_player_material <name>`
* `r_player_techtype <index>`
* `mvm_usedefaultbinds [1/0]`

##### [IW3MVM](https://codmvm.com/mod/iw3mvm) must be injected before cod4tweaks for `mvm` prefixed commands and dvars to work!

#### Auto Record Output Template

* `<map>`
* `<time>`
* `<clientnum>`
* `<killcam>`
* `<ip>`
* `<team>`
* `<name>`

##### Exmaple: `demo_<name>_<map>_` would result in `demo_kruumy_mp_crash_0.dm_1`.