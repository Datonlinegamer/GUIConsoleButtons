#include <iostream>
#include <string>

class ConsoleButton
{
protected:
	std::string m_Label;

public:
	ConsoleButton(std::string label)
	:m_Label(label)
	{

	}
	virtual void Draw() = 0;

};

struct CheckBox
{
	virtual void Draw() =0;
};

class GUIFactory
{
public:
	virtual ConsoleButton* CreateButton(std::string label) = 0;
	virtual CheckBox* CreateCheckBox() = 0;
};

class XboxButton : public ConsoleButton
{
public:
	XboxButton(std::string label)
		:ConsoleButton(label)
	{

	}

	virtual void Draw() override
	{
		std::cout << "A:" << m_Label;
	}
};

class XboxCheckBox :public CheckBox
{
	virtual void Draw() override
	{
		std::cout << " Xbox CheckBox" << std::endl;
	}

};

class XboxFactory : public GUIFactory
{
	virtual ConsoleButton* CreateButton(std::string label) override
	{
		return new XboxButton(label);
	}

	virtual CheckBox* CreateCheckBox() override
	{
		return new XboxCheckBox();	
	}

};
class PlayStationButton : public ConsoleButton
{
public:
	PlayStationButton(std::string label)
		:ConsoleButton(label)
	{

	}

	virtual void Draw() override
	{
		std::cout << "X:" << m_Label;
	}
};
class PlayStationCheckBox :public CheckBox
{
	virtual void Draw() override
	{
		std::cout << " PlayStation CheckBox" << std::endl;
	}

};
class PlayStationFactory : public GUIFactory
{
	virtual ConsoleButton* CreateButton(std::string label) override
	{
		return new PlayStationButton(label);
	}

	virtual CheckBox* CreateCheckBox() override
	{
		return new PlayStationCheckBox();
	}
};

GUIFactory* GetGUIFactory()
{
#ifdef XBOX
	return new  XboxFactory();
#else PLAYSTATION
return new PlayStationFactory();
#endif 

	
	
}

int main()
{
	GUIFactory* pFactory = GetGUIFactory();
	ConsoleButton* pButton = pFactory->CreateButton("Main Menu" " -");
	CheckBox* pCheckBox = pFactory->CreateCheckBox();

	pButton->Draw();
	pCheckBox->Draw();

	delete pButton;
	pButton = nullptr;

	delete pFactory;
	pFactory = nullptr;
}