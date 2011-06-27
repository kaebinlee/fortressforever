#ifndef FF_CUSTOMHUDOPTIONS_ASSIGNPRESETS_H
#define FF_CUSTOMHUDOPTIONS_ASSIGNPRESETS_H

#include "ff_optionspage.h"
#include "ff_customhudoptions_arrangementpresets.h"
#include "ff_customhudoptions_stylepresets.h"
#include "ff_customhudoptions_positionpresets.h"

#include "keyvalues.h"
#include "filesystem.h"
#include "ff_quantitypanel.h"

#include <vgui_controls/ComboBox.h>
#include <vgui_controls/Button.h>

#define	PRESETCOMOBO_ROW_HEIGHT 30
#define	PRESETCOMOBO_X 180
#define	PRESETCOMOBO_Y 80

using namespace vgui;

class CFFCustomHudAssignPresets : public CFFOptionsPage
{
	DECLARE_CLASS_SIMPLE(CFFCustomHudAssignPresets, CFFOptionsPage);
	
public:
	CFFCustomHudAssignPresets(Panel *parent, char const *panelName, CFFCustomHudStylePresets* stylePresetsClass, CFFCustomHudArrangementPresets* arrangementPresetsClass, CFFCustomHudPositionPresets* positionPresetsClass);
	~CFFCustomHudAssignPresets();

	virtual void Load();
	virtual void Reset();
	virtual void Apply();
	
	bool IsReady();
	void ApplyAssignmentToControls(KeyValues *kvAssignment);
	void UpdateSecondaryComboFromParentKey(KeyValues *kvPrimary);

	void StylePresetUpdated(const char *pszPresetName);
	void StylePresetRenamed(const char *pszOldPresetName, const char *pszNewPresetName);
	void StylePresetDeleted(const char *pszDeletedPresetName);
	void StylePresetAdded(const char *pszPresetName, KeyValues *kvPreset);

	void ArrangementPresetUpdated(const char *pszPresetName);
	void ArrangementPresetRenamed(const char *pszOldPresetName, const char *pszNewPresetName);
	void ArrangementPresetDeleted(const char *pszDeletedPresetName);
	void ArrangementPresetAdded(const char *pszPresetName, KeyValues *kvPreset);

	void PositionPresetUpdated(const char *pszPresetName);
	void PositionPresetRenamed(const char *pszOldPresetName, const char *pszNewPresetName);
	void PositionPresetDeleted(const char *pszDeletedPresetName);
	void PositionPresetAdded(const char *pszPresetName, KeyValues *kvPreset);

	void OnStylePresetsClassLoaded();
	void OnArrangementPresetsClassLoaded();
	void OnPositionPresetsClassLoaded();

	void RegisterAssignmentChange(KeyValues *kvSelf, KeyValues* kvParent = NULL);
	
	KeyValues* GetStyleDataForAssignment(KeyValues *kvAssignment);
	void SendStyleDataToAssignment(KeyValues *kvAssignment);
	void CreatePresetFromPanelDefault(KeyValues *kvPresetData);
private:
	//-----------------------------------------------------------------------------
	// Purpose: Catch quantity panels requesting to be added for 
	//-----------------------------------------------------------------------------
	MESSAGE_FUNC_PARAMS(OnAddQuantityPanel, "AddQuantityPanel", data);

	//-----------------------------------------------------------------------------
	// Purpose: Catch the comboboxs changing their selection
	//-----------------------------------------------------------------------------
	MESSAGE_FUNC_PARAMS(OnUpdateCombos, "TextChanged", data);

	//-----------------------------------------------------------------------------
	// Purpose: Catch the checkboxes changing their state
	//-----------------------------------------------------------------------------
	MESSAGE_FUNC_PARAMS(OnUpdateCheckbox, "CheckButtonChecked", data);
	
	//-----------------------------------------------------------------------------
	// Purpose: Catch the "Copy Default" buttons
	//-----------------------------------------------------------------------------
	MESSAGE_FUNC_PARAMS(OnButtonCommand, "Command", data);

	ComboBox		*m_pPrimary, *m_pSecondary;
	ComboBox		*m_pStylePresets, *m_pArrangementPresets, *m_pPositionPresets;

	Button			*m_pCopyDefaultStyle, *m_pCopyDefaultArrangement, *m_pCopyDefaultPosition;

	KeyValues		*m_kvLoadedAssignments;
	KeyValues		*m_kvRequiredUpdates;

	CFFCustomHudArrangementPresets *m_pArrangementPresetsClass;
	CFFCustomHudStylePresets *m_pStylePresetsClass;
	CFFCustomHudPositionPresets *m_pPositionPresetsClass;

	bool m_bAssignmentPositionChanging;
	bool m_bAssignmentArrangementChanging;
	bool m_bAssignmentStyleChanging;

	bool m_bCopyDefaultPosition;
	bool m_bCopyDefaultArrangement;
	bool m_bCopyDefaultStyle;

	bool m_bLoaded;
	bool m_bIsLoading;
	int iYCoords;
};

extern CFFCustomHudAssignPresets *g_AP;

#endif