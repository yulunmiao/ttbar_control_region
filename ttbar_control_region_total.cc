#include "Color.h"
#define NBIN 1
#define INF 0
#define SUP 1
#define LUMI 59.74

int ttbar_control_region_total(){
 	gStyle->SetOptStat(0);

	THStack *hs=new THStack("",";;N/Events");
	double scale;
	TFile *file;
	TLegend *l=new TLegend(0.15,0.6,0.35,0.85);

	/*ttbar*/
	TChain *ttbar_lep=new TChain("t");
	//ttbar_lep->Add("./TTTo2L2Nu/TTTo2L2Nu.root");
	ttbar_lep->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/TTTo2L2Nu.root");
	TH1F *httbar=new TH1F("t#bar{t}","t#bar{t}",NBIN,INF,SUP);
	//file=TFile::Open("./TTTo2L2Nu/TTTo2L2Nu.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/TTTo2L2Nu.root");
	scale=72100 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();	
	for(unsigned int i=0;i<ttbar_lep->GetEntries();i++){
		httbar->Fill(0.,scale);
	}

	TChain *ttbar_semilep=new TChain("t");
	//ttbar_semilep->Add("./TTToSemiLeptonic/TTToSemiLeptonic.root");
	ttbar_semilep->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext3-v1_NANOAODSIM_2018_mc_sep3_2020/TTToSemiLeptonic.root");
	//file=TFile::Open("./TTToSemiLeptonic/TTToSemiLeptonic.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext3-v1_NANOAODSIM_2018_mc_sep3_2020/TTToSemiLeptonic.root");
        scale=365340 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<ttbar_semilep->GetEntries();i++){
                httbar->Fill(0.,scale);
        }

	httbar->SetFillColor(cBlue);
	hs->Add(httbar);
	l->AddEntry(httbar,"t#bar{t}","f");
	/*ttbar*/
        /*ttW*/
        TH1F *httw=new TH1F("ttw","ttw",NBIN,INF,SUP);
        TChain *ttw=new TChain("t");
        ttw->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/ttW.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/ttW.root");
        scale=0.2043 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<ttw->GetEntries();i++){
                httw->Fill(0.,scale);
        }
        httw->SetFillColor(cOrange);
        hs->Add(httw);
        l->AddEntry(httw,"ttW","f");
        /*ttW*/
        /*ttZ*/
        TH1F *httz=new TH1F("ttz","ttz",NBIN,INF,SUP);
        TChain *ttz_1to10=new TChain("t");
        ttz_1to10->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/ttZ_1to10.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/ttZ_1to10.root");
        scale=0.0493 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<ttz_1to10->GetEntries();i++){
                httz->Fill(0.,scale);
        }
        TChain *ttz_10=new TChain("t");
        ttz_10->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/ttZ_10.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/ttZ_10.root");
        scale=0.2529 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();

        for(unsigned int i=0;i<ttz_10->GetEntries();i++){
                httz->Fill(0.,scale);
        }

        httz->SetFillColor(cBrown);
        hs->Add(httz);
        l->AddEntry(httz,"ttZ","f");
        /*ttZ*/
	/*DY*/
	TChain *dy_50=new TChain("t");
	TH1F *hdy=new TH1F("DY","DY",NBIN,INF,SUP);
	dy_50->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/DY_50.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/DY_50.root");
	scale=6197.9 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<dy_50->GetEntries();i++){
		hdy->Fill(0.,scale);
	}

	TChain *dy_10to50=new TChain("t");
	dy_10to50->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/DY_10to50.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/DY_10to50.root");
	scale=20657 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<dy_10to50->GetEntries();i++){
		hdy->Fill(0.,scale);
	}

	hdy->SetFillColor(cYellow);
	hs->Add(hdy);
	l->AddEntry(hdy,"DY","f");
	/*DY*/
	/*WZ*/
	TChain *wz=new TChain("t");
	TH1F *hwz=new TH1F("WZ","WZ",NBIN,INF,SUP);
	wz->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WZ.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WZ.root");
	scale=4.4296 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<wz->GetEntries();i++){
		hwz->Fill(0.,scale);
	}

	hwz->SetFillColor(cViolet);
	hs->Add(hwz);
	l->AddEntry(hwz,"WZ","f");
	/*WZ*/
	/*WW*/
	TChain *ww=new TChain("t");
	TH1F *hww=new TH1F("WW","WW",NBIN,INF,SUP);
	ww->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WW_TuneCP5_13TeV-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WW.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WW_TuneCP5_13TeV-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WW.root");
	scale=118.71 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<ww->GetEntries();i++){
                hww->Fill(0.,scale);
        }

	TChain *ww_ds=new TChain("t");
	ww_ds->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WW_DoubleScattering_13TeV-pythia8_TuneCP5_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WW_DoubleScattering.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WW_DoubleScattering_13TeV-pythia8_TuneCP5_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WW_DoubleScattering.root");
	scale=1.617 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<ww_ds->GetEntries();i++){
                hww->Fill(0.,scale);
        }

	TChain *wpwp=new TChain("t");
	wpwp->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WpWpJJ_EWK-QCD_TuneCP5_13TeV-madgraph-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WpWp.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WpWpJJ_EWK-QCD_TuneCP5_13TeV-madgraph-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WpWp.root");
	scale=0.0539 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<wpwp->GetEntries();i++){
                hww->Fill(0.,scale);
        }

	hww->SetFillColor(kRed);
	hs->Add(hww);
	l->AddEntry(hww,"WW","f");
	/*WW*/
	/*ZZ*/
	TChain *zz=new TChain("t");
	TH1F *hzz=new TH1F("zz","zz",NBIN,INF,SUP);
	zz->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext2-v1_NANOAODSIM_2018_mc_sep3_2020/ZZ.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext2-v1_NANOAODSIM_2018_mc_sep3_2020/ZZ.root");
	scale=1.256 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<zz->GetEntries();i++){
		hzz->Fill(0.,scale);
	}
	hzz->SetFillColor(kViolet);
	hs->Add(hzz);
	l->AddEntry(hzz,"ZZ","f");
	/*ZZ*/
	/*WWG*/
	TH1F *hwwg=new TH1F("wwg","wwg",NBIN,INF,SUP);
	TChain *wwg=new TChain("t");
	wwg->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WWG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WWG.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WWG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WWG.root");
	scale=0.2147 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<wwg->GetEntries();i++){
		hwwg->Fill(0.,scale);
	}
	hwwg->SetFillColor(cGreen);
	hs->Add(hwwg);
	l->AddEntry(hwwg,"WW#gamma","f");
	/*WWG*/
	/*WZG*/
        TH1F *hwzg=new TH1F("wzg","wzg",NBIN,INF,SUP);
	TChain *wzg=new TChain("t");
        wzg->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WZG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WZG.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WZG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WZG.root");
	scale=0.04123 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<wzg->GetEntries();i++){
                hwzg->Fill(0.,scale);
        }
        hwzg->SetFillColor(cPink);
        hs->Add(hwzg);
        l->AddEntry(hwzg,"WZ#gamma","f");
	/*WZG*/
	/*Wjets*/
	TH1F *hwjets=new TH1F("wjets","wjets",NBIN,INF,SUP);
	TChain *wjets1=new TChain("t");
	wjets1->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets1.root");
	file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets1.root");
	scale=1676.9 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<wjets1->GetEntries();i++){
		hwjets->Fill(0.,scale);
	}

	TChain *wjets2=new TChain("t");
        wjets2->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets2.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets2.root");
        scale=494.43 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<wjets2->GetEntries();i++){
                hwjets->Fill(0.,scale);
        }

	TChain *wjets3=new TChain("t");
        wjets3->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets3.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets3.root");
        scale=70.189 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<wjets3->GetEntries();i++){
                hwjets->Fill(0.,scale);
        }

        TChain *wjets4=new TChain("t");
        wjets4->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets4.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets4.root");
        scale=17.438 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<wjets4->GetEntries();i++){
                hwjets->Fill(0.,scale);
        }

        TChain *wjets5=new TChain("t");
        wjets5->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets5.root");
        file=TFile::Open("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_mc_sep3_2020/2018/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets5.root");
        scale=7.8077 * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
        for(unsigned int i=0;i<wjets5->GetEntries();i++){
                hwjets->Fill(0.,scale);
        }
        hwjets->SetFillColor(kCyan);
	hs->Add(hwjets);
        l->AddEntry(hwjets,"W+jet","f");

	
	/*Wjets*/
	/*data*/
	TChain *data=new TChain("t");
	int run,evt;
	data->SetBranchAddress("Common_run",&run);
	data->SetBranchAddress("Common_evt",&evt);
	//data->Add("./data/data.root");
        data->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_data_sep3_2020/data.root");
        TH1F *hdata=new TH1F("","",NBIN,INF,SUP);
	vector<long long> checkDuplicates;
	checkDuplicates.clear();
        for(unsigned int i=0;i<data->GetEntries();i++){
		data->GetEntry(i);
		bool duplicates=false;
		long long RUNPREF=1000*1000;
		long long dupCheck = run*RUNPREF + evt;
		for (unsigned int uid = 0; uid < checkDuplicates.size(); uid++){
			if (checkDuplicates[uid] == dupCheck){
				duplicates=true;
				break;
			}
                }
		if(duplicates==true) continue;
		checkDuplicates.push_back(dupCheck);
		hdata->Fill(0.);
        }
	hdata->SetMarkerStyle(8);
        hdata->SetMarkerColor(1);
	l->AddEntry(hdata,"data");
	/*data*/
	TCanvas *c=new TCanvas();
	hs->SetMinimum(0);
	hs->Draw("hist");
	hdata->Draw("ex0 same");
	l->Draw();
	return 0;
}
