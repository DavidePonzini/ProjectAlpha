#pragma once

class PInventoryItem
{
public:
	virtual bool IsStackable() const = 0;
	virtual int GetCategory() const = 0;
	virtual int GetMaxCount() const = 0;
};
