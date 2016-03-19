# Zoho_Class_Work
//
//  main.c
//  karthik
//
//  Created by R.M.D ENGINEERIN COLLEGE on 19/03/16.
//  Copyright © 2016 R.M.D ENGINEERIN COLLEGE. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct candidates
{
    char *name;
    char *party;
    int party_number;
    int votecount;
};

int main(int argc, const char * argv[]) {
    int i,j;
    char *tempname;
    char *tempparty;
    int tempno;
    int temp;
    int nota=0;
    tempname=(char *)malloc(10*sizeof(char));
    tempparty=(char *)malloc(10*sizeof(char));
    printf("Enter the number of candidates:\n");
    int candidates_count;
    scanf("%d",&candidates_count);
    struct candidates *candobj;
    candobj=(struct candidates*)malloc(candidates_count*sizeof(struct candidates));
    printf("Enter the candidates info:name , partyname , partyno\n");
    for(i=0;i<candidates_count;i++)
    {
        scanf("%s%s",tempname,tempparty);
        scanf("%d",&tempno);
        candobj[i].name=(char*)malloc(10*sizeof(char));
        candobj[i].party=(char*)malloc(10*sizeof(char));
        strcpy(candobj[i].name,tempname);
        strcpy(candobj[i].party,tempparty);
        candobj[i].party_number=tempno;
        candobj[i].votecount=0;
    }
    printf("The info about the candidates are :\n");
    for(i=0;i<candidates_count;i++)
    {
        printf("%s\n%s\n%d\n",candobj[i].name,candobj[i].party,candobj[i].party_number);
        printf("\n");
    }
    printf("Enter the number of people in the constituency :\n");
    int people_count,flagship;
    scanf("%d",&people_count);
    for(i=0;i<people_count;i++)
    {
        printf("Enter the party number u want to vote for:\n");
        scanf("%d",&temp);
        flagship=0;
        for(j=0;j<candidates_count;j++)
        {
            if(temp==candobj[j].party_number)
            {
                candobj[j].votecount=candobj[j].votecount+1;
                flagship=1;
                break;
            }
        }
        if(flagship==0)
        {
            nota+=1;
        }
    }
    int max;
    char *winner;
    winner=(char *)malloc(30*sizeof(char));
    max=candobj[0].votecount;
    strcpy(winner,candobj[0].name);
    for(i=1;i<candidates_count;i++)
    {
        if(candobj[i].votecount>max)
        {
            max=candobj[i].votecount;
            strcpy(winner,candobj[i].name);
        }
    }
    printf("The winner is %s\n",winner);
    return 0;
}
