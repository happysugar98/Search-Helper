#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include "kid.h"
#include "add.h"
#include "alert.h"

void add::init_()
{
	place_.bind(*this);
	place_.div("margin=[5,5,5,5] <vert margin=[5,5,5,5] <vert weight=135 margin=[5,5,5,5] gap=2 browser_typing><vert margin=[5,5,5,5] gap=2 browser_adding>><vert margin=[5,5,5,5] <vert weight=135 margin=[5,5,5,5] <vert margin=[5,5,5,5] gap=2 arrange=[15,variable] site_typing><vert margin=[5,5,5,5] gap=2 arrange=[15,variable] url_typing>><margin=[5,5,5,5] gap=2 site_adding>>");
	caption("Add_Setting");
	// browser_text
	browser_text.create(*this);
	place_["browser_typing"] << browser_text;
	browser_text.caption("Type the original file name of browser exactly");
	browser_text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
	// browser_box
	browser_box.create(*this);
	place_["browser_typing"] << browser_box;
	// browser_button
	browser_button.create(*this);
	place_["browser_adding"] << browser_button;
	browser_button.caption("add browser");
	// site_text
	site_text.create(*this);
	place_["site_typing"] << site_text;
	site_text.typeface(nana::paint::font("", 8, { 400, false, false, false }));
	site_text.caption("Type the name of website");
	site_text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(0));
	// site_box
	site_box.create(*this);
	place_["site_typing"] << site_box;
	site_box.typeface(nana::paint::font("", 8, { 400, false, false, false }));
	// url_text
	url_text.create(*this);
	place_["url_typing"] << url_text;
	url_text.typeface(nana::paint::font("", 8, { 400, false, false, false }));
	url_text.caption("Type the website's search URL");
	url_text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(0));
	// url_box
	url_box.create(*this);
	place_["url_typing"] << url_box;
	url_box.typeface(nana::paint::font("", 8, { 400, false, false, false }));
	// site_button
	site_button.create(*this);
	place_["site_adding"] << site_button;
	site_button.caption("add website");

	place_.collocate();
}

add::add(kid* kk, nana::window wd, const ::nana::size& sz, const nana::appearance& apr) : nana::form(wd, sz, apr)
{
	init_();
	//<*ctor
	k = kk;
	browser_button.events().click([=]
		{
			std::string binput = browser_box.text();
			std::ofstream bout("browser.txt", std::ios::app);
			bout.put('\n');
			bout << binput;
			bout.close();
			alert a(k, this, 0);
			a.show();
			nana::exec();
		});
	site_button.events().click([=]
		{
			std::string sinput = site_box.text();
			std::string uinput = url_box.text();
			std::ofstream sout("site.txt", std::ios::app);
			std::ofstream uout("url.txt", std::ios::app);
			sout.put('\n');
			sout << sinput;
			uout.put('\n');
			uout << uinput;
			sout.close();
			uout.close();
			alert a(k, this, 0);
			a.show();
			nana::exec();
		});
	//*>
}

add::~add()
{
	delete this;
}