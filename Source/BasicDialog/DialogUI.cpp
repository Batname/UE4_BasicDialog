#include "DialogUI.h"

void UDialogUI::UpdateSubtitles(TArray<FSubtitle> Subtitles)
{
	if (!Subtitles.IsValidIndex(0)) return;

	// Start background task
	(new FAutoDeleteAsyncTask<UMGAsyncTask>(Subtitles, this))->StartBackgroundTask();
}

