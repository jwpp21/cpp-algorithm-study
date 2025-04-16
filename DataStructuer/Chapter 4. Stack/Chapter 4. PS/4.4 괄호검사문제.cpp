
int checkMatching(const char* in) {
	StackType* s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(s);

	for (i = 0;i < n;i++) {
		ch = in[i];
		switch (ch)
		{
		case '(': case '[': case '{':
			push(s, ch);
			break;
		case ')': case ']': case '}':
			if (isEmpty(s)) return 0;
			else {
				open_ch = pop(s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!isEmpty(s)) return 0;
	return 1;
}
