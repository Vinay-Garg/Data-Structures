class cashReg
{
public:
	int currentBalance();

	void acceptAmount(int amountIn);

	cashReg(int cashIn = 500);

private:
	int cashOnHand;
};