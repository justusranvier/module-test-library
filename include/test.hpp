export module myexample;

namespace my_ns
{
class FooPrivate;

export class Foo
{
public:
    auto grok() const noexcept -> const char*;

    Foo() noexcept;
    ~Foo();

private:
    FooPrivate* imp_;
};
}  // namespace my_ns
