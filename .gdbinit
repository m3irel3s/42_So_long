#GDB Settings
set print pretty on
set print array on

set style enabled on


set logging on

define main
	disp *argv@argc
	disp *temp_b
	disp temp_b
end

define init_game_struct
	disp *game
end

define init_map_struct
	disp *map
end

define init_pos_struct
	disp *position
end

fs cmd
file so_long
break init_game_struct
break init_map_struct
break init_pos_struct
run ola.ber

info break
info watch