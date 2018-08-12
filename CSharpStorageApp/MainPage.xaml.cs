using Windows.UI.Xaml.Controls;
using StorageWrapperComponent;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace CSharpStorageApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
            //RawAPIexample();
            //WrapperAPIexample();
            RawCompositeExample();
            WrapperCompositeExample();
        }
        private void RawAPIexample()
        {
            Windows.Storage.ApplicationDataContainer localSettings =
                Windows.Storage.ApplicationData.Current.LocalSettings;

            localSettings.Values["RawKey"] = 123;
            int result = (int)(localSettings.Values["RawKey"]);
            localSettings.Values.Clear();
        }
        private void WrapperAPIexample()
        {
            UWPStorage storage = new UWPStorage(StorageType.Local);
            storage.SetInt32("WrapperKey", 456);
            bool exists = false;
            int result = storage.GetInt32("WrapperKey", out exists, 444);
            storage.Clear();
        }
        private void RawCompositeExample()
        {
            Windows.Storage.ApplicationDataContainer localSettings = Windows.Storage.ApplicationData.Current.LocalSettings;

            // Create a composite setting
            Windows.Storage.ApplicationDataCompositeValue composite = new Windows.Storage.ApplicationDataCompositeValue();
            composite["intVal"] = 1212;
            composite["strVal"] = "string";

            localSettings.Values["RawCompositeSetting"] = composite;

            // Read data from a composite setting
            Windows.Storage.ApplicationDataCompositeValue composite2 =
               (Windows.Storage.ApplicationDataCompositeValue)localSettings.Values["RawCompositeSetting"];

            if (composite2!=null)
            {
                // Access data in composite2["intVal"] and composite2["strVal"]
                int one = (int)(composite2["intVal"]);
                string hello = composite2["strVal"].ToString();
            }

            // Delete a composite setting
            localSettings.Values.Remove("RawCompositeSetting");
        }
        private void WrapperCompositeExample()
        {
            UWPStorage storage = new UWPStorage(StorageType.Local);
            // Create a composite setting
            CompositeValue composite = new CompositeValue();
            composite.SetInt32("intVal", 3434);
            composite.SetString("strVal", "string");

            storage.SetComposite("WrapperCompositeSetting", composite);

            // Read data from a composite setting
            bool exists = false;
            CompositeValue composite2 = storage.GetComposite("WrapperCompositeSetting", out exists);
            if (exists)
            {
                // Access data in composite2["intVal"] and composite2["strVal"]
                int one = composite2.GetInt32("intVal", out exists, 4444);
                string hello = composite2.GetString("strVal", out exists, "error");
            }
            // Delete a composite setting
            storage.Remove("WrapperCompositeSetting");
        }

    }
}
