#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

//Global Variables
int mn_ch, kp, kp2, kp3, sec, start, rdm, wrng = 0, seg, lvl, fl_sz = 0, chk_1=0;
int ctr_rdm, ctr_temp, ctr_ans, ctr_db;
int temp[100], db[100];
char temp_ans[100], com_ans[100];
char ans;
int rdm1, rdm2, rdm3, ctr_seg2;
char seg2_uin[500], oprtr_2[50];
int seg2_a[100], seg2_b[100], seg2_cans[100], seg2_uans[100], oprtr[100], seg2_temp[100];
FILE *fp;

//Function Declaration

//Main Menu
int menu();
int cntinu();
int n_game();
int about();
int end_msg();

//System
int fetch_games();
int save_game();
int cnfm_1();
int cnfm_2();

//Games
int seg1_lvl1();
int seg1_lvl2();
int seg1_lvl3();
int seg2_lvl1();
int seg2_lvl2();

//Main Function
int main()
{
printf("Checking System...\n");
_sleep(500);
printf("Checking Database...\n");
_sleep(500);
printf("Checking Segments...\n");
_sleep(500);
printf("Checking Levels...\n");
_sleep(500);
printf("Getting It Ready...\n\n");
_sleep(1000);
system("pause");
system("cls");
menu();
}

//Function Definition
int menu()
{
    printf("\tWelcome To Number Fishing!!\n-------------------------------------------\n");
    printf("\nYou Like Maths? Have A Good Memorizing Power?\nThen Show Me What You've Got!!\n\n");
    do
    {
        printf("1. Continue\n2. New Game\n3. About\n4. Exit\n");
        printf("=> ");
        scanf("%d", &mn_ch);
    }
    while(mn_ch != 1 && mn_ch != 2 && mn_ch != 3 && mn_ch != 4);
    if(mn_ch == 1)
    {
       system("cls");
       cntinu();
    }

    else if(mn_ch == 2)
    {
        system("cls");
        n_game();
    }

    else if(mn_ch == 3)
    {
        system("cls");
        about();
    }

    else
        exit(0);
}

int cntinu()
{
fp = fopen("db.txt", "r");

fseek(fp,0,SEEK_END);
fl_sz = ftell(fp);

if(fl_sz == 0)
{
    printf("No Saved Game Found\n");
    cnfm_1();
}
else
{
    fetch_games();
}
fclose(fp);
}

int n_game()
{
    seg1_lvl1();
}

int about()
{
    printf("\t\tAbout\n-------------------------------------------\n");
    printf("Developers:\nSudhin Sarker Bishal\nSaidul Islam Satil\nfrom Daffodil International University\n\n");
    printf("Spacial Thanks To:\nKaushik Sarker\nLecturer, Daffodil International University\n");
    cnfm_1();
}

int seg1_lvl1()
{
    seg = 1; lvl = 1; wrng = 0;

    //Saving History
    save_game();

    srand((unsigned)time(NULL));
    system("cls");
    printf("\tSegment 1: Specify Odd and Even\n\t\tLevel 1\n------------------------------------------\n");
    printf("\n1. There Will Be 8 Numbers In Front Of You Only For 5 Seconds.\n2. You Have To Memorise It.");
    printf("\n3. After That A Box Will Apear To Take Your Answers. The Box Will Be Like 'Start Recalling:'");
    printf("\n4. Answer Them Sequentially As The Numbers Will Be. For Odd = 'o' And For Even = 'e'");
    printf("\n5. Press Enter Everytime Whenever You Are Giving Your 'e' or 'o'");
    printf("\n6. You Can Only Go To The Next Level When You Make Your All The Answers Correct\n\n");
    system("pause");
    system("cls");
    printf("\tSegment 1: Specify Odd and Even\n\t\tLevel 1\n------------------------------------------\n");

    //Generating Random Numbers and Processing Result
    for(ctr_rdm=0; ctr_rdm<8; ctr_rdm++)
    {
    rdm = rand()%50;
    temp[ctr_rdm] = rdm;
    if(rdm%2 == 0)
    {
    com_ans[ctr_rdm] = 'e';
    }
    else
    {
    com_ans[ctr_rdm] = 'o';
    }
    }

    //Printing Numbers
    for(ctr_temp=0; ctr_temp<8; ctr_temp++)
    {
    printf("%d\n", temp[ctr_temp]);
    }

    //Timer
    time_t start;
    time_t s,t;
    int sec = 5;
    start = time(NULL)+sec;

    while(time(NULL)<start)
    {

    }

    //Player's Answers
    system("cls");
    printf("\t\tStart Recalling\n------------------------------------------\n\n");
    time(&s);

    //Checking The Value Whether It's '1'/'0' Or Not
    ctr_ans = 0;
    while(ctr_ans<8)
    {
    printf("%dth Number: ", ctr_ans+1);
    scanf("%s", &ans);
    if(ans != 'e' && ans !='o')
    {
        printf("Only 'o' And 'e' Is Valid..\n");
    }
    else
    {
    temp_ans[ctr_ans] = ans;
    ctr_ans++;
    }
    }
    time(&t);

    //Processing Result
    system("cls");
    printf("\t\tResults\n------------------------------------------\n");

    for(ctr_ans=0; ctr_ans<8; ctr_ans++)
    {
    printf("%d = %c\t",temp[ctr_ans],com_ans[ctr_ans]);
    printf("| Your's = ");
    printf("%c\n",temp_ans[ctr_ans]);
    if(temp_ans[ctr_ans]!=com_ans[ctr_ans])
    {
    wrng = wrng + 1;
    }
    }
    printf("------------------------------------------\n");
    printf("\nTarget:8\nIncorrect Answers:%d\nYou Took: %g Seconds\n\n", wrng, difftime(t,s));

    if(wrng != 0)
    {
        printf("You Need To Make All Your Answers Correct To Go To Next Level..\n");
        cnfm_2();
    }

    else
    {
        printf("Congratulation Buddy!! You Won!! Ready To Go Next?\n");

    do
    {
        printf("1. Next\n2. Go Back\n3. Exit\n");
        printf("=> ");
        scanf("%d",&kp3);
    }
    while(kp3 != 1 && kp3 != 2 && kp3 != 3);

    if(kp3 == 1)
    {
        system("cls");
        seg1_lvl2();
    }
    else if(kp3 == 2)
    {
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
    }
    wrng = 0;
}

int seg1_lvl2()
{
    seg = 1; lvl = 2; wrng = 0;

    //Saving History
    save_game();

    srand((unsigned)time(NULL));
    system("cls");
    printf("\tSegment 1: Specify Odd and Even\n\t\tLevel 2\n------------------------------------------\n");
    printf("\n1. There Will Be 10 Numbers In Front Of You Only For 5 Seconds.\n2. You Have To Memorise It.");
    printf("\n3. After That A Box Will Apear To Take Your Answers. The Box Will Be Like 'Start Recalling:'");
    printf("\n4. Answer Them Sequentially As The Numbers Will Be. For Odd = 'o' And For Even = 'e'");
    printf("\n5. Press Enter Everytime Whenever You Are Giving Your 'e' or 'o'");
    printf("\n6. You Can Only Go To The Next Level When You Make Your All The Answers Correct\n\n");
    system("pause");
    system("cls");
    printf("\tSegment 1: Specify Odd and Even\n\t\tLevel 2\n------------------------------------------\n");

    //Generating Random Numbers and Processing Result
    for(ctr_rdm=0; ctr_rdm<10; ctr_rdm++)
    {
    rdm = rand()%100;
    temp[ctr_rdm] = rdm;
    if(rdm%2 == 0)
    {
    com_ans[ctr_rdm] = 'e';
    }
    else
    {
    com_ans[ctr_rdm] = 'o';
    }
    }

    //Printing Numbers
    for(ctr_temp=0; ctr_temp<10; ctr_temp++)
    {
    printf("%d\n", temp[ctr_temp]);
    }

    //Timer
    time_t start;
    time_t s,t;
    int sec = 5;
    start = time(NULL)+sec;

    while(time(NULL)<start)
    {

    }

    //Player's Answers
    system("cls");
    printf("\t\tStart Recalling\n------------------------------------------\n\n");
    time(&s);

    //Checking The Value Whether It's '1'/'0' Or Not
    ctr_ans = 0;
    while(ctr_ans<10)
    {
    printf("%dth Number: ", ctr_ans+1);
    scanf("%s", &ans);
    if(ans != 'e' && ans !='o')
    {
        printf("Only 'o' And 'e' Is Valid..\n");
    }
    else
    {
    temp_ans[ctr_ans] = ans;
    ctr_ans++;
    }
    }
    time(&t);

    //Processing Result
    system("cls");
    printf("\t\tResults\n------------------------------------------\n");

    for(ctr_ans=0; ctr_ans<10; ctr_ans++)
    {
    printf("%d = %c\t",temp[ctr_ans],com_ans[ctr_ans]);
    printf("| Your's = ");
    printf("%c\n",temp_ans[ctr_ans]);
    if(temp_ans[ctr_ans]!=com_ans[ctr_ans])
    {
    wrng = wrng + 1;
    }
    }
    printf("------------------------------------------\n");
    printf("\nTarget:10\nIncorrect Answers:%d\nYou Took: %g Seconds\n\n", wrng, difftime(t,s));

    if(wrng != 0)
    {
        printf("You Need To Make All Your Answers Correct To Go To Next Level..\n");
        cnfm_2();
    }

    else
    {
        printf("Congratulation Buddy!! You Won!! Ready To Go Next?\n");

    do
    {
        printf("1. Next\n2. Go Back\n3. Exit\n");
        printf("=> ");
        scanf("%d",&kp3);
    }
    while(kp3 != 1 && kp3 != 2 && kp3 != 3);

    if(kp3 == 1)
    {
        system("cls");
        seg1_lvl3();
    }
    else if(kp3 == 2)
    {
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
    }
    wrng = 0;
}

int seg1_lvl3()
{
    seg = 1; lvl = 3; wrng = 0;

    //Saving History
    save_game();

    srand((unsigned)time(NULL));
    system("cls");
    printf("\tSegment 1: Specify Odd and Even\n\t\tLevel 3\n------------------------------------------\n");
    printf("\n1. There Will Be 10 Numbers In Front Of You Only For 3 Seconds.\n2. You Have To Memorise It.");
    printf("\n3. After That A Box Will Apear To Take Your Answers. The Box Will Be Like 'Start Recalling:'");
    printf("\n4. Answer Them Sequentially As The Numbers Will Be. For Odd = 'o' And For Even = 'e'");
    printf("\n5. Press Enter Everytime Whenever You Are Giving Your 'e' or 'o'");
    printf("\n6. You Can Only Go To The Next Level When You Make Your All The Answers Correct\n\n");
    system("pause");
    system("cls");
    printf("\tSegment 1: Specify Odd and Even\n\t\tLevel 3\n------------------------------------------\n");

    //Generating Random Numbers and Processing Result
    for(ctr_rdm=0; ctr_rdm<10; ctr_rdm++)
    {
    rdm = rand()%100;
    temp[ctr_rdm] = rdm;
    if(rdm%2 == 0)
    {
    com_ans[ctr_rdm] = 'e';
    }
    else
    {
    com_ans[ctr_rdm] = 'o';
    }
    }

    //Printing Numbers
    for(ctr_temp=0; ctr_temp<10; ctr_temp++)
    {
    printf("%d\n", temp[ctr_temp]);
    }

    //Timer
    time_t start;
    time_t s,t;
    int sec = 4;
    start = time(NULL)+sec;

    while(time(NULL)<start)
    {

    }

    //Player's Answers
    system("cls");
    printf("\t\tStart Recalling\n------------------------------------------\n\n");
    time(&s);

    //Checking The Value Whether It's '1'/'0' Or Not
    ctr_ans = 0;
    while(ctr_ans<10)
    {
    printf("%dth Number: ", ctr_ans+1);
    scanf("%s", &ans);
    if(ans != 'e' && ans !='o')
    {
        printf("Only 'o' And 'e' Is Valid..\n");
    }
    else
    {
    temp_ans[ctr_ans] = ans;
    ctr_ans++;
    }
    }
    time(&t);

    //Processing Result
    system("cls");
    printf("\t\tResults\n------------------------------------------\n");

    for(ctr_ans=0; ctr_ans<10; ctr_ans++)
    {
    printf("%d = %c\t",temp[ctr_ans],com_ans[ctr_ans]);
    printf("| Your's = ");
    printf("%c\n",temp_ans[ctr_ans]);
    if(temp_ans[ctr_ans]!=com_ans[ctr_ans])
    {
    wrng = wrng + 1;
    }
    }
    printf("------------------------------------------\n");
    printf("\nTarget:10\nIncorrect Answers:%d\nYou Took: %g Seconds\n\n", wrng, difftime(t,s));

    if(wrng != 0)
    {
        printf("You Need To Make All Your Answers Correct To Go To Next Level..\n");
        cnfm_2();
    }

    else
    {
         printf("Congratulation Buddy!! You Won!! Ready To Go Next?\n");

    do
    {
        printf("1. Next\n2. Go Back\n3. Exit\n");
        printf("=> ");
        scanf("%d",&kp3);
    }
    while(kp3 != 1 && kp3 != 2 && kp3 != 3);

    if(kp3 == 1)
    {
        system("cls");
        seg2_lvl1();
    }
    else if(kp3 == 2)
    {
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
    }
    wrng = 0;
}

int seg2_lvl1()
{
    seg = 2; lvl = 1; wrng = 0;

    //Saving History
    save_game();

    system("cls");
    printf("\tSegment 2: Calculations In Seconds\n\t\tLevel 1\n------------------------------------------\n");
    printf("\n1. You'll Have 10 Basic Mathematics With '+' and '-'.");
    printf("\n2. You'll Have 22 Seconds To Answer Correctly For Winning The Level.");
    printf("\n3. Press Enter Everytime Whenever You Are Giving Your Answers\n\n");
    system("pause");
    system("cls");
    printf("\tSegment 2: Calculations In Seconds\n\t\tLevel 1\n------------------------------------------\n");

    //Generating Random Numbers
    srand((unsigned)time(NULL));
    for(ctr_rdm=0; ctr_rdm<10; ctr_rdm++)
    {
    rdm1 = rand()%20;
    rdm2 = rand()%20;
    rdm3 = rand()%2;
    seg2_a[ctr_rdm] = rdm1;
    seg2_b[ctr_rdm] = rdm2;
    oprtr[ctr_rdm] = rdm3;
    }

    //Timer
    time_t s,t;

    //Setting The Answers
    int z1,z2;
    for(ctr_ans=0; ctr_ans<10; ctr_ans++)
    {
    if(oprtr[ctr_ans] == 0)
    {
    if((seg2_a[ctr_ans]+seg2_b[ctr_ans]) == 0)
    {
    z1 = seg2_a[ctr_ans]+1;
    seg2_a[ctr_ans] = z1;
    z2 = seg2_b[ctr_ans];
    seg2_cans[ctr_ans] = z1 + z2;
    }
    else
    {
    seg2_cans[ctr_ans] = (seg2_a[ctr_ans] + seg2_b[ctr_ans]);
    }
    oprtr_2[ctr_ans] = '+';
    }

    else
    {
    if(seg2_a[ctr_ans]>seg2_b[ctr_ans])
    {
    if((seg2_a[ctr_ans]-seg2_b[ctr_ans] == 0))
    {
    z1 = seg2_a[ctr_ans]+1;
    seg2_a[ctr_ans] = z1;
    z2 = seg2_b[ctr_ans];
    seg2_cans[ctr_ans] = z1 - z2;
    }
    else
    {
    seg2_cans[ctr_ans] = (seg2_a[ctr_ans] - seg2_b[ctr_ans]);
    }
    oprtr_2[ctr_ans] = '-';
    }

    else
    {
    if((seg2_b[ctr_ans]-seg2_a[ctr_ans] == 0))
    {
    z1 = seg2_a[ctr_ans];
    seg2_a[ctr_ans] = z1;
    z2 = seg2_b[ctr_ans]+1;
    seg2_cans[ctr_ans] = z2 - z1;
    }
    else
    {
    seg2_cans[ctr_ans] = (seg2_b[ctr_ans] - seg2_a[ctr_ans]);
    }
    oprtr_2[ctr_ans] = '-';
    }
    }
    }

    //Printing Numbers and Getting Answers
    int cnvrt;
    ctr_temp=0;
    time(&s);
    while(ctr_temp<10)
    {
    if(oprtr_2[ctr_temp] == '+')
    {
    printf("%d ", seg2_a[ctr_temp]);
    printf("%c ", oprtr_2[ctr_temp]);
    printf("%d = ", seg2_b[ctr_temp]);
    }

    else
    {
       if(seg2_a[ctr_temp]>seg2_b[ctr_temp])
       {
         printf("%d ", seg2_a[ctr_temp]);
         printf("%c ", oprtr_2[ctr_temp]);
         printf("%d = ", seg2_b[ctr_temp]);
       }
       else
       {
         printf("%d ", seg2_b[ctr_temp]);
         printf("%c ", oprtr_2[ctr_temp]);
         printf("%d = ", seg2_a[ctr_temp]);
       }
    }
    scanf("%s", &seg2_uin);
    cnvrt = atoi(seg2_uin);

    //Checking Whether It's Integer Or Not
    if(cnvrt==0)
    {
        printf("Only Digits Are Valid...\n");
    }
    else
    {
        seg2_uans[ctr_temp] = cnvrt;
        ctr_temp++;
    }
    }
    time(&t);

    //Generating Result
    system("cls");
    printf("\t\tResults\n------------------------------------------\n");
    int ctr_ans2;
    wrng = 0;
    for(ctr_ans2=0; ctr_ans2<10; ctr_ans2++)
    {
    if(oprtr_2[ctr_ans2] == '+')
    {
    printf("%d ", seg2_a[ctr_ans2]);
    printf("%c ", oprtr_2[ctr_ans2]);
    printf("%d = ", seg2_b[ctr_ans2]);
    printf("%d\t", seg2_cans[ctr_ans2]);
    printf("| Your's : %d\n", seg2_uans[ctr_ans2]);
    }

    else
    {
       if(seg2_a[ctr_ans2]>seg2_b[ctr_ans2])
       {
         printf("%d ", seg2_a[ctr_ans2]);
         printf("%c ", oprtr_2[ctr_ans2]);
         printf("%d = ", seg2_b[ctr_ans2]);
         printf("%d\t", seg2_cans[ctr_ans2]);
         printf("| Your's : %d\n", seg2_uans[ctr_ans2]);
       }
       else
       {
         printf("%d ", seg2_b[ctr_ans2]);
         printf("%c ", oprtr_2[ctr_ans2]);
         printf("%d = ", seg2_a[ctr_ans2]);
         printf("%d\t", seg2_cans[ctr_ans2]);
         printf("| Your's : %d\n", seg2_uans[ctr_ans2]);
       }
    }
    if(seg2_cans[ctr_ans2]!=seg2_uans[ctr_ans2])
    {
    wrng = wrng + 1;
    }
    }
    printf("------------------------------------------\n");
    printf("\nTarget:10\nIncorrect Answers:%d\n\nTarget Time:22 Sec\nYou Took:%g Sec\n\n", wrng, difftime(t,s));

    if(wrng != 0)
    {
        printf("You Need To Make All Your Answers Correct To Go To Next Level..\n");
        cnfm_2();
    }

    else if(difftime(t,s)>22)
    {
        printf("Too Slow...\n");
        cnfm_2();
    }

    else
    {
         printf("Congratulation Buddy!! You Won!! Ready To Go Next?\n");

    do
    {
        printf("1. Next\n2. Go Back\n3. Exit\n");
        printf("=> ");
        scanf("%d",&kp3);
    }
    while(kp3 != 1 && kp3 != 2 && kp3 != 3);

    if(kp3 == 1)
    {
        system("cls");
        seg2_lvl2();
    }
    else if(kp3 == 2)
    {
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
    }
    wrng = 0;
}

int seg2_lvl2()
{
    seg = 2; lvl = 2; wrng = 0;

    //Saving History
    save_game();

    system("cls");
    printf("\tSegment 2: Calculations In Seconds\n\t\tLevel 2\n------------------------------------------\n");
    printf("\n1. You'll Have 10 Maths With Multiplications.");
    printf("\n2. You'll Have 20 Seconds To Answer Correctly For Winning The Level.");
    printf("\n3. Press Enter Everytime Whenever You Are Giving Your Answers\n\n");
    system("pause");
    system("cls");
    printf("\tSegment 2: Calculations In Seconds\n\t\tLevel 2\n------------------------------------------\n");

    //Generating Random Numbers
    srand((unsigned)time(NULL));
    for(ctr_rdm=0; ctr_rdm<10; ctr_rdm++)
    {
    rdm1 = rand()%20;
    rdm2 = rand()%20;
    seg2_a[ctr_rdm] = rdm1;
    seg2_b[ctr_rdm] = rdm2;
    }

    //Timer
    time_t s,t;

    //Setting The Answers
    for(ctr_ans=0; ctr_ans<10; ctr_ans++)
    {
    seg2_cans[ctr_ans] = seg2_a[ctr_ans]*seg2_b[ctr_ans];
    oprtr_2[ctr_ans] = '*';
    }

    //Printing Numbers and Getting Answers
    int cnvrt;
    ctr_temp=0;
    time(&s);
    while(ctr_temp<10)
    {
    printf("%d ", seg2_a[ctr_temp]);
    printf("%c ", oprtr_2[ctr_temp]);
    printf("%d = ", seg2_b[ctr_temp]);

    scanf("%s", &seg2_uin);
    cnvrt = atoi(seg2_uin);

    //Checking Whether It's Integer Or Not
    if(cnvrt==0)
    {
        printf("Only Digits Are Valid...\n");
    }
    else
    {
        seg2_uans[ctr_temp] = cnvrt;
        ctr_temp++;
    }
    }
    time(&t);

    //Generating Result
    system("cls");
    printf("\t\tResults\n------------------------------------------\n");
    int ctr_ans2;
    wrng = 0;
    for(ctr_ans2=0; ctr_ans2<10; ctr_ans2++)
    {
    printf("%d ", seg2_a[ctr_ans2]);
    printf("%c ", oprtr_2[ctr_ans2]);
    printf("%d = ", seg2_b[ctr_ans2]);
    printf("%d\t", seg2_cans[ctr_ans2]);
    printf("| Your's : %d\n", seg2_uans[ctr_ans2]);

    if(seg2_cans[ctr_ans2]!=seg2_uans[ctr_ans2])
    {
    wrng = wrng + 1;
    }
    }

    printf("------------------------------------------\n");
    printf("\nTarget:10\nIncorrect Answers:%d\n\nTarget Time:20 Sec\nYou Took:%g Sec\n\n", wrng, difftime(t,s));

    if(wrng != 0)
    {
        printf("You Need To Make All Your Answers Correct To Go To Next Level..\n");
        cnfm_2();
    }

    else if(difftime(t,s)>20)
    {
        printf("Too Slow...\n");
        cnfm_2();
    }

    else
    {
        end_msg();
    }
    wrng = 0;
}


int fetch_games()
{
    fp = fopen("db.txt", "r");
    for(ctr_db=0; ctr_db<2; ctr_db++)
    {
        fscanf(fp, "%d", &db[ctr_db]);
    }

    if(db[0] == 1 && db[1] == 1)
    {
        seg1_lvl1();
    }

    else if(db[0] == 1 && db[1] == 2)
    {
        seg1_lvl2();
    }

    else if(db[0] == 1 && db[1] == 3)
    {
        seg1_lvl3();
    }

    else if(db[0] == 2 && db[1] == 1)
    {
        seg2_lvl1();
    }

    else if(db[0] == 2 && db[1] == 2)
    {
        seg2_lvl2();
    }

    else
    {
        printf("Database Error!\n");
        cnfm_1();
    }
}

int save_game()
{
    fp = fopen("db.txt", "w");
    fprintf(fp,"%d\n%d", seg, lvl);
    fclose(fp);
}

int cnfm_1()
{

    do
    {
        printf("Press '1' To Go Back And 'O' To Exit...\n");
        scanf("%d",&kp);
    }
    while(kp != 1 && kp != 0);

    if(kp == 1)
    {
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
}

int cnfm_2()
{
   do
    {
        printf("So, What Are You Going To Do?");
        printf("\n1. Play Again\n2. Go Back\n3. Exit\n");
        printf("=> ");
        scanf("%d",&kp2);
    }
    while(kp2 != 1 && kp2 != 2 && kp2 != 3);

    if(kp2 == 1)
    {
        system("cls");
        cntinu();
    }
    else if(kp2 == 2)
    {
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
}

int end_msg()
{
   printf("Congratulations For Winning The Series!!\n-------------------------------------------\n");
   printf("The Purpose of Creating This Game is to Increase Your Math and Memorizing Skills\nBased on The Researches by Scientists.\n");
   printf("Have This Game Succeeded in It's Purpose? Give Your Feedback:\nsudhin35-985@diu.edu.bd\nsaidul35-891@diu.edu.bd\nThank You!!\n\n");
   cnfm_1();
}

