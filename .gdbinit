#GDB Settings
set print pretty on
set print array on

set style enabled on


set logging enabled on

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

define map_name_checker
	disp extension
	disp map->map_name
end

define read_map_lines
	disp *map
	disp map->grid[i]
	disp map->grid
	disp line
	disp fd
end

define get_player_position
	disp *pos
	disp map->grid[i][j]
	disp i
	disp j
end

fs cmd
file so_long
break main
break get_player_position
run ./src/maps/valid_maps/long_map.ber

info break
info watch