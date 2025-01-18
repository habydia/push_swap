/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:28:33 by hadia             #+#    #+#             */
/*   Updated: 2025/01/18 05:10:32 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*fonction creer pile b

ALGORITHM
h = 1
while h < n, h = 3*h + 1
while h > 0,
    h = h / 3
    for k = 1:h, insertion sort a[k:h:n]
    → invariant: each h-sub-array is sorted
end

Java Code
public void shellSort(int[] array) {
     int[] gaps = { 701, 301, 132, 57, 23, 10, 4, 1 };
     int temp;
     int i, j;

     for (int gap : gaps) {
          for (i = gap; i < array.length; i++) {
               temp = array[ i ];
               for (j = i; j >= gap && array[ j - gap ] > temp; j -= gap) {
                    array[ j ] = array[ j - gap ];
               }
               array[ j ] = temp;
          }
     }
}*/

/*int	ft_median(t_list **pile_a)
{
	int i, j, temp;
	int size = ft_strlen(tab);

	// Return the median element
	if (size % 2 == 0)
		return (tab[size / 2 - 1] + tab[size / 2]) / 2;
	else
		return tab[size / 2];
}*/
int ft_sorter(t_list **pile_a, t_list **pile_b)
{
// 	int Vpivot = ft_median(pile a);
// 	t_list **pile_b;
// 	t_list **pile_a;

	// ft_init(pile_a, pile_b, pivot);
	// // - organiser pile a ordre croissant
	// //insertion sort, shell sort 
	// // - organiser pile b ordre decroissant
	
	// // - reinserrer tous les element pile a
	// //print instructions realise suivis de \n 

	// return (suites instruction)
}