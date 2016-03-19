# Zoho_Class_Work
//
//  main.c
//  knapsack.c
//
//  Created by R.M.D ENGINEERIN COLLEGE on 19/03/16.
//  Copyright © 2016 R.M.D ENGINEERIN COLLEGE. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct bag
{
    int weight;
    int value;
    int count;
    int orderfinder;
    int order;
};

int main(int argc, const char * argv[]) {
    int bagvalue=0,bagweight;
    int j,temp;
    int *sorter;
    int *flagship;
    printf("Enter the max capacity of the bag :\n");
    int maxcapacity;
    scanf("%d",&maxcapacity);
    
    bagweight=maxcapacity;
    
    printf("Enter the number of weights :\n");
    int bag_count;
    scanf("%d",&bag_count);
    
    printf("Enter the weights and value of each weights and number of such weights :\n");
    
    struct bag *bagobj;
    bagobj=(struct bag*)malloc(bag_count*sizeof(struct bag));
    
    int temp1,temp2,temp3,i;
    for(i=0;i<bag_count;i++)
    {
        scanf("%d%d%d",&temp1,&temp2,&temp3);
        bagobj[i].weight=temp1;
        bagobj[i].value=temp2;
        bagobj[i].count=temp3;
    }
    
    printf("The object finder is :\n");
    for(i=0;i<bag_count;i++)
    {
        bagobj[i].orderfinder=(maxcapacity/bagobj[i].weight)*bagobj[i].value;
        printf("%d\n",bagobj[i].orderfinder);
    }
    
    sorter=(int *)malloc(bag_count*sizeof(int));
    for(i=0;i<bag_count;i++)
    {
        sorter[i]=bagobj[i].orderfinder;
    }
    
    for(i=0;i<bag_count;i++)
    {
        for(j=i+1;j<bag_count;j++)
        {
            if(sorter[i]<sorter[j])
            {
                temp=sorter[i];
                sorter[i]=sorter[j];
                sorter[j]=temp;
            }
        }
    }
    
    printf("The sorted order is \n");
    for(i=0;i<bag_count;i++)
    {
        printf("%d\n",sorter[i]);
    }
    
    flagship=(int *)malloc(bag_count*sizeof(int));
    for(i=0;i<bag_count;i++)
    {
        flagship[i]=0;
    }
    
    for(i=0;i<bag_count;i++)
    {
        temp=sorter[i];
        for(j=0;j<bag_count;j++)
        {
            if(temp==bagobj[j].orderfinder)
            {
                if(flagship[j]==0)
                {
                    bagobj[j].order=i;
                    flagship[j]=1;
                }
            }
        }
    }
    
    printf("Checking the bag order:\n");
    for(i=0;i<bag_count;i++)
    {
        for(j=0;j<bag_count;j++)
        {
            if(bagobj[j].order==i)
            {
                printf("bag finder value is %d\n",bagobj[j].orderfinder);
            }
        }
    }
    
    int weightreduction,k,tempweightreduce;
    
    printf("The bag value printing is :\n");
    for(i=0;i<bag_count;i++)
    {
        //printf("Hi1\n");
        if(bagvalue>=0)
        {
            for(j=0;j<bag_count;j++)
            {
                //printf("Hi2\n");
                if(bagobj[j].order==i)
                {
                    if(bagweight>=bagobj[j].weight)
                    {
                        for(k=0;k<bagobj[j].count;k++)
                        {
                            tempweightreduce=bagobj[j].weight;
                            if(bagweight-tempweightreduce>=0)
                            {
                                bagvalue=bagvalue+bagobj[j].value;
                                bagweight=bagweight-tempweightreduce;
                            }
                            else
                            {
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    
    printf("The bag value is %d\n",bagvalue);
    return 0;
}
