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
    if(num == MOV_RRA)
        write(1,"rra\n",4);
    if(num == MOV_RRB )
        write(1,"rrb\n",4);
    if(num == MOV_RRR )
        write(1,"rrr\n",4);
}

void t_move_rot(int ra,int rb)
{
    while(ra > 0 && rb > 0)
    {
        ra --;
        rb --;
        t_move_print(MOV_RR);
    }
    while(ra < 0 && rb < 0)
    {
        ra ++;
        rb ++;
        t_move_print(MOV_RRR);
    }
    while(ra < 0)
    {
        ra ++;
        t_move_print(MOV_RRA);
    }
    while(ra > 0)
    {
        ra --;
        t_move_print(MOV_RA);
    }
    while(rb > 0)
    {
        rb --;
        t_move_print(MOV_RB);
    }
    while(rb < 0)
    {
        rb ++;
        t_move_print(MOV_RRB);
    }
}


void t_game_solution(t_game * game)
{
    t_stack * head;
    int ra;
    int rb;

    if(game == NULL || game->move == NULL)
        return ;
    head = game->move;
    ra = 0;
    rb = 0;
    while(head)
    {
        ra+= (head->num == MOV_RA || head->num == MOV_RR);
        rb+=(head->num == MOV_RB || head->num == MOV_RR);
        ra-=(head->num == MOV_RRA || head->num == MOV_RRR);
        rb-=(head->num == MOV_RRB || head->num == MOV_RRR);
        if(head->num < 4)
        { 
            t_move_rot(ra,rb);
            ra = 0;
            rb = 0;
            t_move_print(head->num);            
        }
        head = head->next;
    }
    t_move_rot(ra,rb);
}

