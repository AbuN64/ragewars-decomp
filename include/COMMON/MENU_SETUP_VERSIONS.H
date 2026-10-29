#ifndef COMMON_MENU_SETUP_VERSIONS_H
#define COMMON_MENU_SETUP_VERSIONS_H
#if defined(VERSION_US_REV1)
#endif

/* Versioned setup strings and control identifiers from the native menu tables. */
#if defined(VERSION_US)
extern s8 g_modeToken[8];
#elif defined(VERSION_EU)
extern s8 g_modeToken[8];
#elif defined(VERSION_EU_X)
extern s8 g_modeToken[8];
#elif defined(VERSION_DE)
extern s8 g_modeToken[8];
#else
extern s8 g_modeToken[8];
#endif
#if defined(VERSION_DE)
extern s32 g_pakProfileOperationPhase;
#elif defined(VERSION_US)
extern s32 g_pakDialogProbeStateUs;
#elif defined(VERSION_EU)
extern s32 g_pakDialogProbeStateEu;
#elif defined(VERSION_EU_X)
extern s32 g_pakDialogProbeStateEuX;
#else
extern s32 g_pakDialogProbeStateUsRev1;
#endif
#if defined(VERSION_DE)
enum { SETUP_LABEL_ID = 641 };
enum { PANEL_ROOT_ID = 737 };
enum { PANEL_TEXT_ID = 739 };
enum { MODE_DEFAULT_ID = 862 };
enum { MODE_17_ID = 866 };
enum { MODE_2_ID = 864 };
enum { MODE_3_ID = 865 };
enum { MODE_46_ID = 867 };
enum { MODE_5_ID = 863 };
enum { MODE_HIDE_ID = 738 };
enum { SLOT_DEFAULT_ID = 652 };
enum { SLOT_1_ID = 654 };
enum { SLOT_2_ID = 656 };
enum { SLOT_3_ID = 658 };
enum { CHECK_0_ID = 662 };
enum { CHECK_1_ID = 664 };
enum { CHECK_2_ID = 666 };
enum { CHECK_DEFAULT_ID = 668 };
#elif defined(VERSION_EU_X)
enum { SETUP_LABEL_ID = 650 };
enum { PANEL_ROOT_ID = 721 };
enum { PANEL_TEXT_ID = 723 };
enum { MODE_DEFAULT_ID = 877 };
enum { MODE_17_ID = 881 };
enum { MODE_2_ID = 879 };
enum { MODE_3_ID = 880 };
enum { MODE_46_ID = 882 };
enum { MODE_5_ID = 878 };
enum { MODE_HIDE_ID = 722 };
enum { SLOT_DEFAULT_ID = 660 };
enum { SLOT_1_ID = 662 };
enum { SLOT_2_ID = 664 };
enum { SLOT_3_ID = 666 };
enum { CHECK_0_ID = 671 };
enum { CHECK_1_ID = 673 };
enum { CHECK_2_ID = 675 };
enum { CHECK_DEFAULT_ID = 677 };
#else
enum { SETUP_LABEL_ID = 645 };
enum { PANEL_ROOT_ID = 705 };
enum { PANEL_TEXT_ID = 709 };
enum { MODE_DEFAULT_ID = 836 };
enum { MODE_17_ID = 840 };
enum { MODE_2_ID = 838 };
enum { MODE_3_ID = 839 };
enum { MODE_46_ID = 841 };
enum { MODE_5_ID = 837 };
enum { MODE_HIDE_ID = 708 };
enum { SLOT_DEFAULT_ID = 651 };
enum { SLOT_1_ID = 653 };
enum { SLOT_2_ID = 655 };
enum { SLOT_3_ID = 657 };
enum { CHECK_0_ID = 665 };
enum { CHECK_1_ID = 667 };
enum { CHECK_2_ID = 669 };
enum { CHECK_DEFAULT_ID = 671 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_1_2EC = 719 };
enum { UI_CASE_1_2EE = 721 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_1_2EC = 744 };
enum { UI_CASE_1_2EE = 746 };
#else
enum { UI_CASE_1_2EC = 748 };
enum { UI_CASE_1_2EE = 750 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_2_2D4 = 672 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_2_2D4 = 720 };
#else
enum { UI_CASE_2_2D4 = 724 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_3_2BB = 725 };
enum { UI_CASE_3_2BC = 727 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_3_2BB = 732 };
enum { UI_CASE_3_2BC = 733 };
#else
enum { UI_CASE_3_2BB = 699 };
enum { UI_CASE_3_2BC = 700 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_4_2D5 = 742 };
enum { UI_CASE_4_2DA = 744 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_4_2D5 = 750 };
enum { UI_CASE_4_2DA = 757 };
#else
enum { UI_CASE_4_2D5 = 725 };
enum { UI_CASE_4_2DA = 730 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_6_2E4 = 681 };
enum { UI_CASE_6_2E8 = 687 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_6_2E4 = 709 };
enum { UI_CASE_6_2E8 = 713 };
#else
enum { UI_CASE_6_2E4 = 740 };
enum { UI_CASE_6_2E8 = 744 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_7_2CA = 751 };
enum { UI_CASE_7_2CC = 753 };
enum { UI_CASE_7_2CB = 754 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_7_2CA = 740 };
enum { UI_CASE_7_2CC = 741 };
enum { UI_CASE_7_2CB = 739 };
#else
enum { UI_CASE_7_2CA = 714 };
enum { UI_CASE_7_2CC = 716 };
enum { UI_CASE_7_2CB = 715 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_8_2CE = 755 };
enum { UI_CASE_8_2CF = 757 };
enum { UI_CASE_8_2CB = 754 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_8_2CE = 736 };
enum { UI_CASE_8_2CF = 737 };
enum { UI_CASE_8_2CB = 739 };
#else
enum { UI_CASE_8_2CE = 718 };
enum { UI_CASE_8_2CF = 719 };
enum { UI_CASE_8_2CB = 715 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_9_2C6 = 688 };
enum { UI_CASE_9_2C8 = 690 };
enum { UI_CASE_9_2C7 = 691 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_9_2C6 = 681 };
enum { UI_CASE_9_2C8 = 684 };
enum { UI_CASE_9_2C7 = 682 };
#else
enum { UI_CASE_9_2C6 = 710 };
enum { UI_CASE_9_2C8 = 712 };
enum { UI_CASE_9_2C7 = 711 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_10_2A4 = 710 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_10_2A4 = 685 };
#else
enum { UI_CASE_10_2A4 = 676 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_11_2D1 = 722 };
enum { UI_CASE_11_2D2 = 723 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_11_2D1 = 726 };
enum { UI_CASE_11_2D2 = 728 };
#else
enum { UI_CASE_11_2D1 = 721 };
enum { UI_CASE_11_2D2 = 722 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_12_2F2 = 729 };
enum { UI_CASE_12_2F3 = 730 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_12_2F2 = 689 };
enum { UI_CASE_12_2F3 = 690 };
#else
enum { UI_CASE_12_2F2 = 754 };
enum { UI_CASE_12_2F3 = 755 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_13_2AF = 711 };
enum { UI_CASE_13_2B6 = 718 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_13_2AF = 759 };
enum { UI_CASE_13_2B6 = 766 };
#else
enum { UI_CASE_13_2AF = 687 };
enum { UI_CASE_13_2B6 = 694 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_17_2A5 = 706 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_17_2A5 = 743 };
#else
enum { UI_CASE_17_2A5 = 677 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_15_2EF = 707 };
enum { UI_CASE_15_2F1 = 709 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_15_2EF = 747 };
enum { UI_CASE_15_2F1 = 749 };
#else
enum { UI_CASE_15_2EF = 751 };
enum { UI_CASE_15_2F1 = 753 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_16_2B7 = 692 };
enum { UI_CASE_16_2B9 = 693 };
enum { UI_CASE_16_2BA = 682 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_16_2B7 = 705 };
enum { UI_CASE_16_2B9 = 707 };
enum { UI_CASE_16_2BA = 706 };
#else
enum { UI_CASE_16_2B7 = 695 };
enum { UI_CASE_16_2B9 = 697 };
enum { UI_CASE_16_2BA = 698 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_21_2E1 = 678 };
enum { UI_CASE_21_2E2 = 680 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_21_2E1 = 729 };
enum { UI_CASE_21_2E2 = 731 };
#else
enum { UI_CASE_21_2E1 = 737 };
enum { UI_CASE_21_2E2 = 738 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_23_2AC = 695 };
enum { UI_CASE_23_2AE = 697 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_23_2AC = 702 };
enum { UI_CASE_23_2AE = 704 };
#else
enum { UI_CASE_23_2AC = 684 };
enum { UI_CASE_23_2AE = 686 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_24_2A9 = 700 };
enum { UI_CASE_24_2AA = 701 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_24_2A9 = 686 };
enum { UI_CASE_24_2AA = 687 };
#else
enum { UI_CASE_24_2A9 = 681 };
enum { UI_CASE_24_2AA = 682 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_25_2EA = 698 };
enum { UI_CASE_25_2EB = 699 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_25_2EA = 700 };
enum { UI_CASE_25_2EB = 701 };
#else
enum { UI_CASE_25_2EA = 746 };
enum { UI_CASE_25_2EB = 747 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_26_2A6 = 703 };
enum { UI_CASE_26_2A7 = 704 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_26_2A6 = 697 };
enum { UI_CASE_26_2A7 = 698 };
#else
enum { UI_CASE_26_2A6 = 678 };
enum { UI_CASE_26_2A7 = 679 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_28_2DE = 673 };
enum { UI_CASE_28_2DF = 674 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_28_2DE = 717 };
enum { UI_CASE_28_2DF = 719 };
#else
enum { UI_CASE_28_2DE = 734 };
enum { UI_CASE_28_2DF = 735 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_29_2BF = 676 };
enum { UI_CASE_29_2C0 = 677 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_29_2BF = 715 };
enum { UI_CASE_29_2C0 = 716 };
#else
enum { UI_CASE_29_2BF = 703 };
enum { UI_CASE_29_2C0 = 704 };
#endif
#endif
