// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class YnovJV2_EscapeTarget : TargetRules
{
	public YnovJV2_EscapeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "YnovJV2_Escape" } );
	}
}
