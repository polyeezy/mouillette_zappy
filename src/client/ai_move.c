/*
** ai_move.c for move in /home/miele_a/Semestre_4/zappy/mouillette_zappy/src/client
**
** Made by Alexis Miele
** Login   <miele_a@epitech.net>
**
** Started on  Wed Jun 22 15:39:10 2016 Alexis Miele
** Last update Wed Jun 22 15:46:51 2016 Alexis Miele
*/

static void	ai_do_move(t_ai *cl, int f1, int d, int f2)
{
  while (f1-- > 0)
    ai_avance(cl);
  if (d < 0)
    ai_gauche(cl);
  else if (d > 0)
    ai_droite(cl);
  while (f2-- > 0)
    ai_avance(cl);
}

void	ai_count_move(t_ai *cl, int cell)
{
  int	i;
  int	j;
  int	k;
  int	last;

  i = 0;
  j = 1;
  k = 1;
  while (!(k > cell && k - j <= cell))
    {
      i++;
      j += 2;
      k += j;
    }
  last = k - (j / 2) - 1;
  if (cell == last)
    last = 0;
  else if (cell < last)
    last = -1;
  else
    last = 1;
  j = ((last - cell) < 0 ? (last - cell) * -1 : last - cell);
  ai_do_move(cl, i, last, j);
}
