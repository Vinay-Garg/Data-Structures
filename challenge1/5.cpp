    int n1,n2,count=0;
    char str1[1000][20],str2[1000][20];

    cin >> n1;
    for(int i=0; i<n1; i++)
        cin >> str1[i];

    cin >> n2;
    for(int i=0; i<n2; i++)
        cin >> str2[i];

    for(int i=0; i<n2; i++)
        {
        count=0;
        for(int j=0; j<n1; j++)
        {
            if(strcmp(str2[i],str1[j]) == 0)
                count ++;
        }
        cout << count << endl;
        }
