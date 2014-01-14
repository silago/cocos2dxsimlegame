#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <ppltasks.h>
#include "huigame.h"
#include "CCApplication.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace Windows::Phone::UI::Input;
using namespace Windows::Graphics::Display;
using namespace concurrency;
USING_NS_CC;

huigame::huigame()
{
}

void huigame::Initialize(CoreApplicationView^ applicationView)
{
	applicationView->Activated +=
		ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &huigame::OnActivated);

	CoreApplication::Suspending +=
		ref new EventHandler<SuspendingEventArgs^>(this, &huigame::OnSuspending);

	CoreApplication::Resuming +=
		ref new EventHandler<Platform::Object^>(this, &huigame::OnResuming);
}

void huigame::SetWindow(CoreWindow^ window)
{
    // Specify the orientation of your application here
    // The choices are DisplayOrientations::Portrait or DisplayOrientations::Landscape or DisplayOrientations::LandscapeFlipped
	DisplayProperties::AutoRotationPreferences = DisplayOrientations::Landscape;

	window->VisibilityChanged +=
		ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &huigame::OnVisibilityChanged);

	window->Closed += 
		ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &huigame::OnWindowClosed);

	window->PointerPressed +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &huigame::OnPointerPressed);

	window->PointerMoved +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &huigame::OnPointerMoved);

	window->PointerReleased +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &huigame::OnPointerReleased);

    CCEGLView* eglView = new CCEGLView();
	eglView->Create(window);
    eglView->setViewName("huigame");
}

void huigame::Load(Platform::String^ entryPoint)
{
}

void huigame::Run()
{
    CCApplication::sharedApplication()->run();
}

void huigame::Uninitialize()
{
}

void huigame::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnVisibilityChanged(sender, args);
}

void huigame::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnWindowClosed(sender, args);
}

void huigame::OnPointerPressed(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerPressed(sender, args);
}

void huigame::OnPointerMoved(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerMoved(sender, args);
}

void huigame::OnPointerReleased(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerReleased(sender, args);
}

void huigame::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
	HardwareButtons::BackPressed += ref new EventHandler<BackPressedEventArgs^>(this, &huigame::OnBackButtonPressed);   
	CoreWindow::GetForCurrentThread()->Activate();
}

void huigame::OnBackButtonPressed(Object^ sender, BackPressedEventArgs^ args)
{
    // Leave args->Handled set to false and the app will quit when user presses the back button on the phone
}

void huigame::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
	// Save app state asynchronously after requesting a deferral. Holding a deferral
	// indicates that the application is busy performing suspending operations. Be
	// aware that a deferral may not be held indefinitely. After about five seconds,
	// the app will be forced to exit.
	SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();
	//m_renderer->ReleaseResourcesForSuspending();

	create_task([this, deferral]()
	{
		// Insert your code here.

		deferral->Complete();
	});
}
 
void huigame::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
	// Restore any data or state that was unloaded on suspend. By default, data
	// and state are persisted when resuming from suspend. Note that this event
	// does not occur if the app was previously terminated.
	// m_renderer->CreateWindowSizeDependentResources();
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
	return ref new huigame();
}

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DApplicationSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}