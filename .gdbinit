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

define map_checker

end

define read_map_lines
	disp *map
	disp map->grid[i]
	disp map->grid
	disp line
	disp fd
end

fs cmd
file so_long
break read_map_lines
run ./src/maps/map.ber

info break
info watch