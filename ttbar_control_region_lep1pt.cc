typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > LV;
#include "Color.h"
#define LUMI 59.74
#define NBIN 20
#define INF 20
#define SUP 250


bool fill_histogram(TH1F* hist,const float cross_section,const char* path){
	TChain *chain=new TChain("t");
	vector<LV> *lepp4=0;
	chain->SetBranchAddress("SS2jet_lep_p4",&lepp4);
	chain->Add(path);
	TFile *file=TFile::Open(path);
	if(!file->IsOpen()) return false;
	float scale= cross_section * 1000 * LUMI / ((TH1F*) file->Get("Wgt__h_nevents"))->Integral();
	for(unsigned int i=0;i<chain->GetEntries();i++){
		chain->GetEntry(i);
		hist->Fill(lepp4->at(0).pt(),scale);
	}
	return true;
}
//cross sections are in pb
//histograms are filled in the function

int ttbar_control_region_lep1pt(){
        gStyle->SetOptStat(0);
	THStack *hs=new THStack("",";;N/Events");
	TLegend *l=new TLegend(0.9,0.6,1.,0.85);
	//ttbar
	TH1F *httbar=new TH1F("t#bar{t}","t#bar{t}",NBIN,INF,SUP);
	fill_histogram(httbar,72.1,"./2018_mc_sep3_2020/2018/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/TTTo2L2Nu.root");
	fill_histogram(httbar,365.34,"./2018_mc_sep3_2020/2018/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext3-v1_NANOAODSIM_2018_mc_sep3_2020/TTToSemiLeptonic.root");
	httbar->SetFillColor(cBlue);
	hs->Add(httbar);
	l->AddEntry(httbar,"t#bar{t}","f");
	//ttbar
	//ttW
	TH1F *httw=new TH1F("ttw","ttw",NBIN,INF,SUP);
	fill_histogram(httw,0.2043,"./2018_mc_sep3_2020/2018/TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/ttW.root");
	httw->SetFillColor(cOrange);
	hs->Add(httw);
	l->AddEntry(httw,"ttW","f");
	//ttW
	//ttZ
	TH1F *httz=new TH1F("ttz","ttz",NBIN,INF,SUP);
	fill_histogram(httz,0.0493,"./2018_mc_sep3_2020/2018/TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/ttZ_1to10.root");
	fill_histogram(httz,0.2529,"./2018_mc_sep3_2020/2018/TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/ttZ_10.root");
	httz->SetFillColor(cBrown);
	hs->Add(httz);
	l->AddEntry(httz,"ttZ","f");
	//ttZ
	//DY
	TH1F *hdy=new TH1F("DY","DY",NBIN,INF,SUP);
	fill_histogram(hdy,6197.9,"./2018_mc_sep3_2020/2018/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/DY_50.root");
	fill_histogram(hdy,20657,"./2018_mc_sep3_2020/2018/DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/DY_10to50.root");
	hdy->SetFillColor(cYellow);
        hs->Add(hdy);
	l->AddEntry(hdy,"DY","f");
	//DY
	//WZ
	TH1F *hwz=new TH1F("wz","wz",NBIN,INF,SUP);
	fill_histogram(hwz,4.4296,"./2018_mc_sep3_2020/2018/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WZ.root");
	hwz->SetFillColor(cViolet);
        hs->Add(hwz);
        l->AddEntry(hwz,"WZ","f");
	//WZ
	//WW
	TH1F *hww=new TH1F("ww","ww",NBIN,INF,SUP);
	fill_histogram(hww,118.71,"./2018_mc_sep3_2020/2018/WW_TuneCP5_13TeV-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WW.root");
	fill_histogram(hww,1.617,"./2018_mc_sep3_2020/2018/WW_DoubleScattering_13TeV-pythia8_TuneCP5_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WW_DoubleScattering.root");
	fill_histogram(hww,0.0539,"./2018_mc_sep3_2020/2018/WpWpJJ_EWK-QCD_TuneCP5_13TeV-madgraph-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WpWp.root");
	hww->SetFillColor(kRed);
        hs->Add(hww);
        l->AddEntry(hww,"WW","f");
	//WW
	//ZZ
	TH1F *hzz=new TH1F("zz","zz",NBIN,INF,SUP);
	fill_histogram(hzz,1.256,"./2018_mc_sep3_2020/2018/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext2-v1_NANOAODSIM_2018_mc_sep3_2020/ZZ.root");
	hzz->SetFillColor(kViolet);
        hs->Add(hzz);
        l->AddEntry(hzz,"ZZ","f");
	//ZZ
	//WWG
	TH1F *hwwg=new TH1F("wwg","wwg",NBIN,INF,SUP);
	fill_histogram(hwwg,0.2417,".//2018_mc_sep3_2020/2018/WWG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1_NANOAODSIM_2018_mc_sep3_2020/WWG.root");
	hwwg->SetFillColor(cGreen);
        hs->Add(hwwg);
        l->AddEntry(hwwg,"WW#gamma","f");
	//WWG
	//WZG
	TH1F *hwzg=new TH1F("wzg","wzg",NBIN,INF,SUP);
	fill_histogram(hwzg,0.04123,"./2018_mc_sep3_2020/2018/WZG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/WZG.root");
	hwzg->SetFillColor(cPink);
        hs->Add(hwzg);
        l->AddEntry(hwzg,"WZ#gamma","f");
	//WZG
	//Wjets
	TH1F *hwjets=new TH1F("wjets","wjets",NBIN,INF,SUP);
	fill_histogram(hwjets,1676.9,"./2018_mc_sep3_2020/2018/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets1.root");
	fill_histogram(hwjets,494.43,"./2018_mc_sep3_2020/2018/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets2.root");
	fill_histogram(hwjets,70.189,"./2018_mc_sep3_2020/2018/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets3.root");
	fill_histogram(hwjets,17.438,"./2018_mc_sep3_2020/2018/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets4.root");
	fill_histogram(hwjets,7.8077,"./2018_mc_sep3_2020/2018/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18NanoAODv6-Nano25Oct2019_102X_upgrade2018_realistic_v20-v1_NANOAODSIM_2018_mc_sep3_2020/Wjets5.root");
	hwjets->SetFillColor(kCyan);
        hs->Add(hwjets);
        l->AddEntry(hwjets,"W+jet","f");
	//Wjets
	//data
        TChain *data=new TChain("t");
        int run,evt;
	vector<LV> *lepp4=0;
        data->SetBranchAddress("SS2jet_lep_p4",&lepp4);
        data->SetBranchAddress("Common_run",&run);
        data->SetBranchAddress("Common_evt",&evt);
        data->Add("/home/yulunmiao/Documents/CMS_data/SS1FatJet/2018_data_sep3_2020/data.root");
        TH1F *hdata=new TH1F("",";p_{t}(GeV);N/Events",NBIN,INF,SUP);
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
                hdata->Fill(lepp4->at(0).pt());
        }
        hdata->SetMarkerStyle(8);
        hdata->SetMarkerColor(1);
        l->AddEntry(hdata,"data");
	//data
        TCanvas *c=new TCanvas();
        hdata->SetMinimum(0);
	hdata->Draw("ex0");
        hs->Draw("hist same");
        hdata->Draw("ex0 same");
        l->Draw();
	return 0;
}
