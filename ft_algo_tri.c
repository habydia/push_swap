/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:28:33 by hadia             #+#    #+#             */
/*   Updated: 2025/01/16 17:52:40 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fonction instruction sa*/
/*fonction instruction sb*/
/*fonction instruction ss*/
/*fonction instruction pa*/
/*fonction instruction pb*/
/*fonction instruction ra*/
/*fonction instruction rb*/
/*fonction instruction rr*/
/*fonction instruction rrb*/
/*fonction instruction rrr*/
/*fonction algo de tri*/
/*ft_pile_b*/
/*#include "algo_tri".h

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
} 
             
int ft_Vpivot(int *tab)
{
	int i, j, temp;
	int size = ft_strlen(tab);

	// Return the median element
	if (size % 2 == 0)
		return (tab[size / 2 - 1] + tab[size / 2]) / 2;
	else
		return tab[size / 2];
}


int *ft_init(int *tab1, int Vpivot)
{
	int *tab2;

	tab2 = malloc(sizeof(tab) * ft_strlen(*tab));
	while (*tab1++ <= Vpivot)
	{
		if (*tab[0] >= Vpivot)
			ra(tab);
		pb(*tab[i], *tab2);
	}
}

ft_algo_tri(pile a)
{
	int pivot;
	int *pile_b;

	pile_b = ft_pile_b(pile_a);
	pivot = ft_Vpivot(pile a);

	ft_init(pile_a, pile_b, pivot);
	- organiser pile a ordre croissant
	//insertion sort, shell sort 
	- organiser pile b ordre decroissant
	
	- reinserrer tous les element pile a
	//print instructions realise suivis de \n 

	return (suites instruction)
}
*/