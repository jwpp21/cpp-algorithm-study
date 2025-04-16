int postixCalculate(string s) {
	int op1, op2, value = 0;
	char ch;
	int n = s.length();
	StackType *k;
	init_stack(k);
	
	for (int i = 0;i < n;i++) {
		ch = s[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(k, value);
		}
		else {
			op2 = pop(k);
			op1 = pop(k);
			switch (ch)
			{
			case '+':
				push(k, op1 + op2);
				break;
			case '-':
				push(k, op1 - op2);
				break;
			case '*':
				push(k, op1 * op2);
				break;
			case '/':
				push(k, op1 / op2);
				break;
			}
		}
	}
	return pop(k);
}
