#include <stdio.h>
#include <string.h>
struct Rescue
{
    int id, people, emergency, priority;
    char location[30], resource[30], team[30], status[20];
};
struct Rescue r[50];
int n = 0;
int main()
{
    int ch, i, j, id, s;
    struct Rescue temp;
    while (1)
    {
        printf("\n1.Register\n2.Display Priority\n3.Assign Team");
        printf("\n4.Update Status\n5.Search\n6.Summary\n7.Exit\n");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter ID, People, Emergency(3-Critical,2-High,1-Normal): ");
            scanf("%d%d%d", &r[n].id, &r[n].people, &r[n].emergency);

            printf("Enter Location: ");
            scanf("%s", r[n].location);

            printf("Enter Resource: ");
            scanf("%s", r[n].resource);

            strcpy(r[n].team, "None");
            strcpy(r[n].status, "Pending");

            if (r[n].emergency == 3)
                r[n].priority = 1;
            else if (r[n].emergency == 2 || r[n].people >= 10)
                r[n].priority = 2;
            else
                r[n].priority = 3;

            n++;
            printf("Request Registered\n");
        }
        else if (ch == 2)
        {
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (r[j].priority > r[j + 1].priority)
                    {
                        temp = r[j];
                        r[j] = r[j + 1];
                        r[j + 1] = temp;
                    }
                }
            }

            for (i = 0; i < n; i++)
            {
                printf("\nID:%d Location:%s People:%d Priority:%d Status:%s Team:%s\n",
                       r[i].id, r[i].location, r[i].people,
                       r[i].priority, r[i].status, r[i].team);
            }
        }
        else if (ch == 3)
        {
            printf("Enter Request ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++)
            {
                if (r[i].id == id)
                {
                    printf("Enter Team Name: ");
                    scanf("%s", r[i].team);
                    printf("Team Assigned\n");
                    break;
                }
            }

            if (i == n)
                printf("Request Not Found\n");
        }
        else if (ch == 4)
        {
            printf("Enter Request ID: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++)
            {
                if (r[i].id == id)
                {
                    printf("1.Pending 2.InProgress 3.Completed: ");
                    scanf("%d", &s);
                    if (s == 1)
                        strcpy(r[i].status, "Pending");
                    else if (s == 2)
                        strcpy(r[i].status, "InProgress");
                    else if (s == 3)
                        strcpy(r[i].status, "Completed");

                    printf("Status Updated\n");
                    break;
                }
            }

            if (i == n)
                printf("Request Not Found\n");
        }
        else if (ch == 5)
        {
            printf("Enter Request ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++)
            {
                if (r[i].id == id)
                {
                    printf("ID:%d Location:%s People:%d Priority:%d Resource:%s Team:%s Status:%s\n",
                           r[i].id, r[i].location, r[i].people,
                           r[i].priority, r[i].resource,
                           r[i].team, r[i].status);
                    break;
                }
            }
            if (i == n)
                printf("Request Not Found\n");
        }
        else if (ch == 6)
        {
            int critical = 0, pending = 0, completed = 0;
            for (i = 0; i < n; i++)
            {
                if (r[i].emergency == 3)
                    critical++;
                if (strcmp(r[i].status, "Pending") == 0)
                    pending++;
                if (strcmp(r[i].status, "Completed") == 0)
                    completed++;
            }
            printf("Total Requests: %d\n", n);
            printf("Critical Requests: %d\n", critical);
            printf("Pending Requests: %d\n", pending);
            printf("Completed Requests: %d\n", completed);
        }
        else if (ch == 7)
        {
            break;
        }
    }
    return 0;
}
