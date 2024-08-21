#ifndef SceneSequence_H
#define SceneSequence_H

class SceneSequence {
public:
	static void Next();
	static void Set(const int num);

private:
	static int current;
};

#endif
