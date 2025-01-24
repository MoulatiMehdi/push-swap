#include "rules.h"

void t_move_print(int num)
{
    if(num == MOV_PA)
        write(1,"pa\n",3);
    if(num == MOV_PB)
        write(1,"pb\n",3);
    if(num == MOV_SA)
        write(1,"sa\n",3);
    if(num == MOV_SB)
        write(1,"sb\n",3);
    if(num == MOV_SS)
        write(1,"ss\n",3);
    if(num == MOV_RA)
        write(1,"ra\n",3);
    if(num == MOV_RB)
        write(1,"rb\n",3);
    if(num == MOV_RR)
        write(1,"rr\n",3);
    if(num ==MOV_RRA)
        write(1,"rra\n",4);
    if(num == MOV_RRB )
        write(1,"rrb\n",4);
    if(num == MOV_RRR )
        write(1,"rrr\n",4);
}

void t_move_rot(int mov[11])
{
    while(mov[MOV_RA] > 0 && mov[MOV_RB] > 0)
    {
        mov[MOV_RA] --;
        mov[MOV_RB] --;
        t_move_print(MOV_RR);
    }
    while(mov[MOV_RA] < 0 && mov[MOV_RB] < 0)
    {
        mov[MOV_RA] ++;
        mov[MOV_RB] ++;
        t_move_print(MOV_RRR);
    }
    while(mov[MOV_RA] < 0)
    {
        mov[MOV_RA] ++;
        t_move_print(MOV_RRA);
    }
    while(mov[MOV_RA] > 0)
    {
        mov[MOV_RA] --;
        t_move_print(MOV_RA);
    }
    while(mov[MOV_RB] > 0)
    {
        mov[MOV_RB] --;
        t_move_print(MOV_RB);
    }
    while(mov[MOV_RB] < 0)
    {
        mov[MOV_RB] ++;
        t_move_print(MOV_RRB);
    }
}


void t_game_solution(t_game * game)
{
    t_stack * head;
    int count [11];
    int i;

    if(game == NULL)
        return ;
    head = game->move;
    if(head == NULL)
        return ;
    i = 0;
    while(i < 11)
        count[i++] = 0;
    while(head)
    {
        if(head->num < 4)
        {
            t_move_rot(count);
            t_move_print(head->num);            
        }else if(head->num >= MOV_RRA)
            count[head->num - 3] --;
        else
            count[head->num] ++;
        head = head->next;
    }
    t_move_rot(count);
}

