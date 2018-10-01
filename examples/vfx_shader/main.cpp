#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include <QtWidgets/qapplication.h>

#include "../vfx_shader/FloatSourceDataModel.h"
#include "../vfx_shader/Float4SourceDataModel.h"
#include "../vfx_shader/ShaderOutDataModel.h"
#include "../vfx_shader/TextDisplayDataModel.h"
#include "../vfx_shader/TextSourceDataModel.h"

using QtNodes::DataModelRegistry;
using QtNodes::FlowView;
using QtNodes::FlowScene;

static std::shared_ptr<DataModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<DataModelRegistry>();

    ret->registerModel<FloatSourceDataModel>();
    ret->registerModel<Float4SourceDataModel>();
    ret->registerModel<ShaderOutDataModel>();
    ret->registerModel<TextDisplayDataModel>();
    ret->registerModel<TextSourceDataModel>();

    return ret;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    FlowScene scene(registerDataModels());
    FlowView view(&scene);

    view.setWindowTitle("VFX Shader generator");
    view.resize(1920, 1080);
    view.show();

    return app.exec();
}