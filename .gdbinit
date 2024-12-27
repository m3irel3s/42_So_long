# #GDB Settings
# set print pretty on
# set print array on

# set style enabled on


# set logging enabled on

# define main
# 	disp *argv@argc
# end

# # define init_game_struct
# # 	disp *game
# # end

# # define init_map_struct
# # 	disp *map
# # end

# # define init_pos_struct
# # 	disp *position
# # end

# # define map_name_checker
# # 	disp extension
# # 	disp map->map_name
# # end

# # define read_map_lines
# # 	disp *map
# # 	disp map->grid[i]
# # 	disp map->grid
# # 	disp line
# # 	disp fd
# # end

# # define get_player_position
# # 	disp *pos
# # 	disp map->grid[i][j]
# # 	disp i
# # 	disp j
# # end

# # define key_press
# # 	disp keycode
# # end

# # define dup_grid
# # 	disp map->grid_copy[i][j]
# # 	disp map->grid[i][j]
# # 	dips i
# # 	disp j

# # end

# # define move_player_left
# # 	disp map->grid[map->player_pos.x - 1][map->player_pos.y]
# # 	disp map->grid[map->player_pos.x][map->player_pos.y]
# # end

# define flood_fill
# 	disp copy[x][y]
# 	disp copy[0]
# 	disp copy[1]
# 	disp copy[2]
# 	disp copy[3]
# 	disp copy[4]
# end

# define render_win
# 	disp map->height
# 	disp map->width
# end

# fs cmd
# file so_long
# break main
# break draw_bg
# run ./src/maps/valid_maps/long_map.ber

# info break
# info watch