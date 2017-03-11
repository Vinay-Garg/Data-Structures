int main()
{
	int n;
	long bign = 0;
	long bignn;
	scanf("%d",&n);
	long arr[n];

	for(int i = 0; i < n; i++)
		scanf("%li", &arr[i]);

	for(int i = 0; i < n; i++)
		bign = bign + (arr[i]) ;

	printf("%ld\n", bign);
	return 0;
}