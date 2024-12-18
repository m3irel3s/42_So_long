/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:08:25 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:39 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

//===============================================================//
//                            MACROS                             //
//===============================================================//

#ifndef M_TRACK
#define M_TRACK printf("File => %s || Func => %s || Malloc\n", __FILE__, __func__)
#endif

//===============================================================//
//                            IMAGES                             //
//===============================================================//

# define PLAYER_FRONT "./assets/front.xpm"
# define COLLECTABLE "./assets/collectable.xpm"
# define WALL "./assets/wall.xpm"
# define FLOOR "./assets/floor.xpm"
# define EXIT "./assets/exit.xpm"


#endif