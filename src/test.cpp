module myexample;

namespace my_ns
{
class FooPrivate
{
public:
    auto grok() const noexcept -> const char*
    {
        return "Hello, World!";
    }
};

Foo::Foo() noexcept
    : imp_(new FooPrivate)
{
}

auto Foo::grok() const noexcept -> const char*
{
    return imp_->grok();
}

Foo::~Foo()
{
    if (nullptr != imp_) {
        delete imp_;
        imp_ = nullptr;
    }
}
}  // namespace my_ns
