// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class YnovJV2_EscapeEditorTarget : TargetRules
{
	public YnovJV2_EscapeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "YnovJV2_Escape" } );
	}
}
