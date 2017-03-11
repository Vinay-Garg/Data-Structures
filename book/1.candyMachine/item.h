class itemType
{
public:
	int count();
	
	int productCost();
	
	void makeSale();

	itemType(int setNoOfItems=50, int setCost=50);
	
private:
	int noOfItems;
	int cost;
};