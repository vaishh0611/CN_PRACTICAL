#include <stdio.h>
int main()
{
	int n,i,ack;
	printf("Enter number of frames:");
	scanf("%d,&n");
	for (i = 1; i<=n; i++)
	{
		printf("\nSender : Sending Frame %d",i);
		printf("\nEnter acknowledgment (1 = received, 0 = not received):");
		scanf("%d, &ack");
		if (ack ==1)
		{
		printf("Snder : ACK received for Frame%d, i");
	}
	else {
		printf("sender : ACK not recived !");
		printf("\nSender : Retransmitting Frame %d",i);
		i--;
	}
	}
	printf("\n\nALL frames transmitted successfully.\n");
	return 0;
}

