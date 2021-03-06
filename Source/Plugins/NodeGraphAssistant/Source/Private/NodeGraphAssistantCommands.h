// Copyright 2018 yangxiangyun
// All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

#include "Style/NGAEditorStyle.h"

class FNodeGraphAssistantCommands : public TCommands<FNodeGraphAssistantCommands>
{

public:
	FNodeGraphAssistantCommands() : TCommands<FNodeGraphAssistantCommands>
	(
		"NodeGraphAssistant",
		NSLOCTEXT("NodeGraphAssistant", "NodeGraphAssistantCommand", "Node graph assistant command"),
		NAME_None,
		FNGAEditorStyle::Get().GetStyleSetName()
	)
	{}

	TSharedPtr< FUICommandInfo > RearrangeNode;
	TSharedPtr< FUICommandInfo > BypassNodes;
	TSharedPtr< FUICommandInfo > SelectDownStreamNodes; 
	TSharedPtr< FUICommandInfo > SelectUpStreamNodes;
	TSharedPtr< FUICommandInfo > CycleWireDrawStyle;
	TSharedPtr< FUICommandInfo > ToggleMaterialGraphWireColor;

	virtual void RegisterCommands() override;
};


#define LOCTEXT_NAMESPACE "FNodeGraphAssistantCommands"

void FNodeGraphAssistantCommands::RegisterCommands()
{
	UI_COMMAND(RearrangeNode, "Rearrange Nodes", "Rearrange Nodes into grid structure", EUserInterfaceActionType::Button, FInputChord(EKeys::R, false, false, true, false));
	UI_COMMAND(BypassNodes, "Bypass Nodes", "Connect selected nodes' inputs to its outputs,remove node if possible", EUserInterfaceActionType::Button, FInputChord(EKeys::X, false, false, true, false));
	UI_COMMAND(SelectDownStreamNodes, "Select downstream nodes", "Select all nodes connected to selected nodes' inputs", EUserInterfaceActionType::Button, FInputChord(EKeys::A, false, false, true, false));
	UI_COMMAND(SelectUpStreamNodes, "Select upstream nodes", "Select all nodes connected to selected nodes' outputs", EUserInterfaceActionType::Button, FInputChord(EKeys::D, false, false, true, false));
	UI_COMMAND(CycleWireDrawStyle, "Wire Style", "Cycle through connection wire drawing style", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ToggleMaterialGraphWireColor, "Wire color", "toggle wire color for material graph", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
