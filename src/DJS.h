#ifndef DJS_H_
#define DJS_H_

class DJS
{
private:
	int *parent, *size;

public:
	DJS();
	void Init(int x);
	int Find (int x);
	void Union (int x, int y);
	virtual ~DJS();
};

#endif /* DJS_H_ */
