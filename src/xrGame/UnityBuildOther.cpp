#include "ui\ArtefactDetectorUI.cpp"
/*#include "ui\CExtraContentFilter.cpp"*/
#include "ui\ChangeWeatherDialog.cpp"
#include "ui\FactionState.cpp"
#include "ui\FractionState.cpp"
#include "ui\map_hint.cpp"
#include "ui\MMSound.cpp"
#include "ui\Restrictions.cpp"
#include "ui\ServerList.cpp"
#include "ui\ServerList_GameSpy_func.cpp"
#include "ui\TeamInfo.cpp"
#include "ui\UIAchievements.cpp"
#include "ui\UIActorMenu.cpp"
#include "ui\UIActorMenuDeadBodySearch.cpp"
#include "ui\UIActorMenuInitialize.cpp"
#include "ui\UIActorMenuInventory.cpp"
#include "ui\UIActorMenuTrade.cpp"
#include "ui\UIActorMenuUpgrade.cpp"
#include "ui\UIActorMenu_action.cpp"
#include "ui\UIActorMenu_script.cpp"
#include "ui\UIActorStateInfo.cpp"
#include "ui\UIBoosterInfo.cpp"
#include "ui\UIBuyWeaponTab.cpp"
#include "ui\UIBuyWndShared.cpp"
#include "ui\UICarPanel.cpp"
#include "ui\UICDkey.cpp"
#include "ui\UICellCustomItems.cpp"
#include "ui\UICellItem.cpp"
#include "ui\UICellItemFactory.cpp"
#include "ui\UIChangeMap.cpp"
#include "ui\UICharacterInfo.cpp"
#include "ui\UIChatWnd.cpp"
#include "ui\UIColorAnimatorWrapper.cpp"
#include "ui\UIDebugFonts.cpp"
#include "ui\UIDemoPlayControl.cpp"
#include "ui\UIDialogWnd.cpp"
#include "ui\UIDragDropListEx.cpp"
#include "ui\UIDragDropReferenceList.cpp"
#include "ui\UIEditKeyBind.cpp"
#include "ui\UIFactionWarWnd.cpp"
/*
#include "ui\UIFrags.cpp"
#include "ui\UIFrags2.cpp"*/
/*#include "ui\UIFrameLine.cpp"*/
#include "ui\UIGameLog.cpp"
#include "ui\UIGameTutorial.cpp"
#include "ui\UIGameTutorialSimpleItem.cpp"
#include "ui\UIGameTutorialVideoItem.cpp"
#include "ui\UIHelper.cpp"
#include "ui\UIHudStatesWnd.cpp"
#include "ui\UIInventoryUpgradeWnd.cpp"
#include "ui\UIInventoryUpgradeWnd_add.cpp"
#include "ui\UIInventoryUtilities.cpp"
#include "ui\UIInvUpgrade.cpp"
#include "ui\UIInvUpgradeInfo.cpp"
#include "ui\UIInvUpgradeProperty.cpp"
#include "ui\UIItemInfo.cpp"
#include "ui\UIKeyBinding.cpp"
#include "ui\UIKickPlayer.cpp"
#include "ui\UILabel.cpp"
/*#include "ui\UIListBox_script.cpp"*/
/*
#include "ui\UIListItem.cpp"
#include "ui\UIListItemAdv.cpp"
#include "ui\UIListItemEx.cpp"*/
#include "ui\UIListItemServer.cpp"
/*
#include "ui\UIListWnd.cpp"
#include "ui\UIListWnd_script.cpp"*/
#include "ui\UILoadingScreen.cpp"
#include "ui\UILogsWnd.cpp"
#include "ui\UIMainIngameWnd.cpp"
#include "ui\UIMap.cpp"
#include "ui\UIMapDesc.cpp"
#include "ui\UIMapInfo.cpp"
#include "ui\UIMapInfo_script.cpp"
#include "ui\UIMapLegend.cpp"
#include "ui\UIMapList.cpp"
#include "ui\UIMapWnd.cpp"
#include "ui\UIMapWnd2.cpp"
#include "ui\UIMapWndActions.cpp"
#include "ui\UIMessageBoxEx.cpp"
#include "ui\UIMessagesWindow.cpp"
#include "ui\UIMMShniaga.cpp"
#include "ui\UIMoneyIndicator.cpp"
#include "ui\UIMotionIcon.cpp"
#include "ui\UIMPAdminMenu.cpp"
#include "ui\UIMPChangeMapAdm.cpp"
#include "ui\UIMpItemsStoreWnd.cpp"
#include "ui\UIMPPlayersAdm.cpp"
#include "ui\UIMPServerAdm.cpp"
#include "ui\UIMpTradeWnd.cpp"
#include "ui\UIMpTradeWnd_init.cpp"
#include "ui\UIMpTradeWnd_items.cpp"
#include "ui\UIMpTradeWnd_misc.cpp"
#include "ui\UIMpTradeWnd_trade.cpp"
#include "ui\UIMpTradeWnd_wpn.cpp"
#include "ui\UINewsItemWnd.cpp"
#include "ui\UIOptConCom.cpp"
#include "ui\UIOutfitInfo.cpp"
#include "ui\UIPdaKillMessage.cpp"
#include "ui\UIPdaMsgListItem.cpp"
#include "ui\UIPdaWnd.cpp"
#include "ui\UIRankIndicator.cpp"
#include "ui\UIRankingWnd.cpp"
#include "ui\UIScriptWnd.cpp"
/*#include "ui\UIScriptWnd_script.cpp"*/
#include "ui\UISecondTaskWnd.cpp"
#include "ui\UIServerInfo.cpp"
#include "ui\UISkinSelector.cpp"
#include "ui\UISleepStatic.cpp"
#include "ui\UISpawnWnd.cpp"
#include "ui\UISpeechMenu.cpp"
#include "ui\UIStatix.cpp"
#include "ui\UIStats.cpp"
#include "ui\UIStatsIcon.cpp"
#include "ui\UIStatsPlayerInfo.cpp"
#include "ui\UIStatsPlayerList.cpp"
#include "ui\UITabButtonMP.cpp"
#include "ui\UITalkDialogWnd.cpp"
#include "ui\UITalkWnd.cpp"
#include "ui\UITaskWnd.cpp"
/*#include "ui\UITextBanner.cpp"*/
#include "ui\UITextVote.cpp"
#include "ui\UITradeWnd.cpp"
#include "ui\UIVote.cpp"
#include "ui\UIVoteStatusWnd.cpp"
#include "ui\UIVotingCategory.cpp"
#include "ui\UIWarState.cpp"
#include "ui\UIWindow_script.cpp"
#include "ui\UIWpnParams.cpp"
#include "ui\UIXmlInit.cpp"
#include "ui\ui_af_params.cpp"
/*#include "UI.cpp"*/
#include "UIAchivementsIndicator.cpp"
#include "UIDialogHolder.cpp"
/*#include "UIFrameRect.cpp"*/
#include "UIGameAHunt.cpp"
#include "UIGameCTA.cpp"
#include "UIGameCustom.cpp"
#include "UIGameCustom_script.cpp"
#include "UIGameDM.cpp"
#include "UIGameMP.cpp"
#include "UIGameSP.cpp"
#include "UIGameTDM.cpp"
/*#include "UIGame_custom_script.cpp"*/
#include "UIPanelsClassFactory.cpp"
#include "UIPlayerItem.cpp"
#include "UITeamHeader.cpp"
#include "UITeamPanels.cpp"
#include "UITeamState.cpp"
#include "UIZoneMap.cpp"
#include "ui_export_script.cpp"
#include "vision_client.cpp"
#include "visual_memory_manager.cpp"
#include "visual_memory_params.cpp"
#include "wallmark_manager.cpp"
#include "Weapon.cpp"
#include "WeaponAK74.cpp"
#include "WeaponAmmo.cpp"
#include "WeaponAutomaticShotgun.cpp"
#include "WeaponBinoculars.cpp"
#include "WeaponBinocularsVision.cpp"
#include "weaponBM16.cpp"
#include "WeaponCustomPistol.cpp"
#include "WeaponCustomPistolAuto.cpp"
#include "WeaponDispersion.cpp"
#include "WeaponFire.cpp"
#include "WeaponFN2000.cpp"
#include "WeaponGroza.cpp"
#include "WeaponHPSA.cpp"
#include "WeaponKnife.cpp"
#include "WeaponLR300.cpp"
#include "WeaponMagazined.cpp"
#include "WeaponMagazinedWGrenade.cpp"
#include "WeaponPistol.cpp"
#include "WeaponPM.cpp"
#include "WeaponRevolver.cpp"
#include "WeaponRG6.cpp"
#include "WeaponRPG7.cpp"
#include "WeaponScript.cpp"
#include "WeaponShotgun.cpp"
#include "WeaponStatMgun.cpp"
#include "WeaponStatMgunFire.cpp"
#include "WeaponStatMgunIR.cpp"
#include "WeaponSVD.cpp"
#include "WeaponUpgrade.cpp"
#include "WeaponVal.cpp"
#include "WeaponVintorez.cpp"
#include "weapon_ammo_dump_impl.cpp"
#include "weapon_dump_impl.cpp"
#include "Wound.cpp"
#include "xrClientsPool.cpp"
#include "xrGame.cpp"
#include "xrGameSpyServer.cpp"
#include "xrGameSpyServer_callbacks.cpp"
#include "xrGameSpy_GameSpyFuncs.cpp"
#include "xrgame_dll_detach.cpp"
#include "xrServer.cpp"
#include "xrServerMapSync.cpp"
#include "xrServer_balance.cpp"
#include "xrServer_CL_connect.cpp"
#include "xrServer_CL_disconnect.cpp"
#include "xrServer_Connect.cpp"
#include "xrServer_Disconnect.cpp"
#include "xrServer_info.cpp"
#include "xrServer_perform_GameExport.cpp"
#include "xrServer_perform_migration.cpp"
#include "xrServer_perform_RPgen.cpp"
#include "xrServer_perform_sls_default.cpp"
#include "xrServer_perform_sls_load.cpp"
#include "xrServer_perform_sls_save.cpp"
#include "xrServer_perform_transfer.cpp"
#include "xrServer_process_event.cpp"
#include "xrServer_process_event_activate.cpp"
#include "xrServer_process_event_destroy.cpp"
#include "xrServer_process_event_ownership.cpp"
#include "xrServer_process_event_reject.cpp"
#include "xrServer_process_spawn.cpp"
#include "xrServer_process_update.cpp"
#include "xrServer_secure_messaging.cpp"
#include "xrServer_sls_clear.cpp"
#include "xrServer_svclient_validation.cpp"
#include "xrServer_updates_compressor.cpp"
/*#include "xr_Client_BattlEye.cpp"*/
#include "xr_level_controller.cpp"
/*#include "xr_Server_BattlEye.cpp"*/
#include "xr_time.cpp"
#include "ZoneCampfire.cpp"
#include "ZoneVisual.cpp"
#include "zone_effector.cpp"
#include "ZudaArtifact.cpp"
