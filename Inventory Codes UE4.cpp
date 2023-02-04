#include "MyInventory.h"
#include "MyItem.h"

// Sets default values for this component's properties
UMyInventory::UMyInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMyInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UMyInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyInventory::AddItem(TSubclassOf<UMyItem> ItemClass)
{
	UMyItem* NewItem = NewObject<UMyItem>(this, ItemClass);
	if (NewItem)
	{
		Inventory.Add(NewItem);
	}
}

void UMyInventory::RemoveItem(UMyItem* Item)
{
	Inventory.Remove(Item);
}

const TArray<UMyItem*>& UMyInventory::GetInventory() const
{
	return Inventory;
}
