//class Collider
//{
//public:
//	Collider() {}
//	virtual ~Collider() {}
//
//	virtual void Update() abstract;
//	virtual void Render(HDC hdc) abstract;
//	virtual bool IsCollision(const Vector& pos) abstract;
//	virtual bool IsCollision(shared_ptr<Collider> other) abstract;
//
//	void SetGreen() { _curPen = 0; }
//	void SetRed() { _curPen = 1; }
//	void SetBlue() { _curPen = 2; }
//
//protected:
//	UINT _curPen = 0;              
//	vector<HPEN> _pens;           
//};
