REM Automatically generated from Makefile
mkdir -p obj
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\bombs.o bombs.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\changes.o changes.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\funtions_map.o funtions_map.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\gbdecompress.o gbdecompress.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\globals.o globals.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\guns.o guns.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\hud.o hud.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\levels_data.o levels_data.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\main.o main.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\map.o map.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\monsters.o monsters.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\others.o others.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\palettes.o palettes.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\robbo.o robbo.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\tiles_data.o tiles_data.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\tiles_helperc.o tiles_helperc.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -Wf-MMD -c -o obj\win_slide.o win_slide.c
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -c -o obj\tiles_helper.o gb\tiles_helper.asm
..\..\..\gbdk\bin\lcc -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 1000000" -Wm-yo4 -Wm-yt17 -Wm-yc -Wf"--data-loc 0xc3a0" -Wf"--code-loc 0x600" -Wl-b_CODE=0x600 -Wl-b_DATA=0xc3a0 -Wl"-g _shadow_OAM=0xC300" -Wl"-g _map=0xC000" -Wl"-g _changes=0xC200" -o obj\Robbo.gb obj\bombs.o obj\changes.o obj\funtions_map.o obj\gbdecompress.o obj\globals.o obj\guns.o obj\hud.o obj\levels_data.o obj\main.o obj\map.o obj\monsters.o obj\others.o obj\palettes.o obj\robbo.o obj\tiles_data.o obj\tiles_helperc.o obj\win_slide.o obj\bombs.o obj\changes.o obj\funtions_map.o obj\gbdecompress.o obj\globals.o obj\guns.o obj\hud.o obj\levels_data.o obj\main.o obj\map.o obj\monsters.o obj\others.o obj\palettes.o obj\robbo.o obj\tiles_data.o obj\tiles_helperc.o obj\win_slide.o obj\tiles_helper.o