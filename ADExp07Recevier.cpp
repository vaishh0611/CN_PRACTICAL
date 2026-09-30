#include <stdio.h>
int main()
{
	int n,i,ack;
	printf("Enter number of frames:");
	scanf("%d,&n");
	for (i = 1; i<=n; i++)
	{
		printf("\nRecevier : Recevier Frame %d",i);
		printf("\nEnter acknowledgment (1 = Sender, 0 = not Sender):");
		scanf("%d, &ack");
		if (ack ==1)
		{
		printf(" Recevier : ACK Sender for Frame%d, i");
	}
	else {
		printf("Recevier : ACK not reciver !");
		printf("\nRecevier : Retransmitting Frame %d",i);
		i--;
	}
	}
	printf("\n\nALL frames transmitted successfully.\n");
	return 0;
}

